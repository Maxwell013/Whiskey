// WindowMacOS.mm

#include <cstddef>
#include <array>

#include <vulkan/vulkan_core.h>
#include <vulkan/vulkan_macos.h>

#import <AppKit/AppKit.h>
#import <Cocoa/Cocoa.h>
#import <QuartzCore/CAMetalLayer.h>

#include "keyCodesMacOS.hpp"
#include "../Window.hpp"

@interface Delegate : NSObject
{ BOOL shouldClose; }
@end

@implementation Delegate
- (BOOL) getShouldClose { return shouldClose; }

- (void) setShouldClose:(BOOL)p_value { shouldClose = p_value; }

- (void) terminateCallback { [self setShouldClose:YES]; }
@end

namespace wsky {

    struct Window::Internal {

    private:
        NSApplication *m_app;
        NSWindow *m_window;
        Delegate *m_delegate;
        std::array<bool, KEY_LAST+1> m_keymap;

    public:

        Internal() : m_app(nullptr), m_window(nullptr), m_delegate(nullptr) {}

        bool create(const std::string& p_title, const int p_width, const int p_height) {

            initApplication();

            initDelegate();

            initWindow(p_title, p_width, p_height);

            initMenu();

            initKeymap();

            return m_window != nil;
        }

        void pollEvents() {
            @autoreleasepool {
                NSEvent *event;
                while ((event = [m_app nextEventMatchingMask:NSEventMaskAny
                                                   untilDate:nil
                                                      inMode:NSDefaultRunLoopMode
                                                     dequeue:YES])) {
                    handleEvent(event);
                    [m_app sendEvent:event];
                    [m_app updateWindows];
                }
            }
        }

        bool shouldClose() const {
            return [m_delegate getShouldClose];
        }

        void close() {
            [m_delegate setShouldClose:true];
        }

        unsigned int getWidth() const { return (unsigned int)[m_window frame].size.width; }

        unsigned int getHeight() const { return (unsigned int)[m_window frame].size.height; }

        VkSurfaceKHR getVulkanSurface(const VkInstance p_instance) const {
            VkMacOSSurfaceCreateInfoMVK createInfo = {};
            createInfo.sType = VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK;
            createInfo.pNext = nullptr;
            createInfo.flags = 0;
            createInfo.pView = m_window.contentView;

            VkSurfaceKHR surface;
            VkResult result = vkCreateMacOSSurfaceMVK(p_instance, &createInfo, nullptr, &surface);
            return (result == VK_SUCCESS) ? surface : VK_NULL_HANDLE;
        }

        bool getKeyIsDown(const int p_keyCode) const {
            return m_keymap[p_keyCode];
        }

        void cleanup() {
            @autoreleasepool {
                [m_window close];
                m_window = nil;
            }
        }

    private:

        void handleEvent(const NSEvent *p_event) {
            switch (p_event.type) {
            case NSEventTypeKeyDown:
                handleKeyEvent(p_event.keyCode, true);
                break;
            case NSEventTypeKeyUp:
                handleKeyEvent(p_event.keyCode, false);
                break;
            case NSEventTypeMouseMoved:
                handleMouseMovedEvent(p_event.deltaX, p_event.deltaY);
                break;
            case NSEventTypeAppKitDefined:
                handleAppKitEvent(p_event);
                break;
            default:
                break;
            }
        }

        void handleKeyEvent(const unsigned short p_keyCode, const bool p_isdown) {
            m_keymap[keyCodeConversionMacOS(p_keyCode)] = p_isdown;
        }

        void handleMouseMovedEvent(const double p_deltaX, const double p_deltaY) {}

        void handleAppKitEvent(const NSEvent *p_event) {
            switch (p_event.subtype) {
            case NSEventSubtypeWindowMoved:
                break;
            default:
                break;
            }
        }

        void initApplication() {
            @autoreleasepool {
                m_app = [NSApplication sharedApplication];
                [m_app setActivationPolicy:NSApplicationActivationPolicyRegular];
                [m_app activateIgnoringOtherApps:YES];
            }
        }

        void initDelegate() {
            @autoreleasepool {
                m_delegate = [[Delegate alloc] init];
                [m_delegate setShouldClose:NO];
            }
        }

        void initWindow(const std::string p_title, const int p_width, const int p_height) {
            @autoreleasepool {
                NSRect rect = NSMakeRect(0, 0, p_width, p_height);
                m_window = [[NSWindow alloc] initWithContentRect:rect
                    styleMask:(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable)
                    backing:NSBackingStoreBuffered
                    defer:NO];
                [m_window setTitle:[NSString stringWithUTF8String:p_title.c_str()]];
                [m_window makeKeyAndOrderFront:nil];

                NSView *view = [m_window contentView];
                [view setWantsLayer:YES];
                view.layer = [CAMetalLayer layer];
            }
        }

        void initMenu() {
            @autoreleasepool {
            // traffic light buttons
            NSButton *closeButton = [m_window standardWindowButton:NSWindowCloseButton];
            [closeButton setTarget:m_delegate];
            [closeButton setAction:@selector(terminateCallback)];

            // main menu
            NSMenu *mainMenu = [[NSMenu alloc] init];

            // app menu
            NSMenuItem *appMenuItem = [[NSMenuItem alloc] init];
            [mainMenu addItem:appMenuItem];

            NSMenu *appMenu = [[NSMenu alloc] initWithTitle:@"Application"];
            [appMenuItem setSubmenu:appMenu];

            // quit item
            NSMenuItem *quitMenuItem = [[NSMenuItem alloc]
                initWithTitle:@"Quit"
                       action:@selector(terminateCallback)
                keyEquivalent:@"q"];
            [quitMenuItem setTarget:m_delegate];
            [quitMenuItem setKeyEquivalentModifierMask:NSEventModifierFlagCommand];

            // main menu
            [appMenu addItem:quitMenuItem];
            [m_app setMainMenu:mainMenu];
            }
        }

        void initKeymap() {
            m_keymap.fill(false);
        }
    };

    Window::Window() { m_window = new Internal(); }

    Window::~Window() { delete m_window; }

    bool Window::create(const std::string& p_title, const int p_width, const int p_height) {
        return m_window->create(p_title, p_width, p_height);
    }

    void Window::cleanup() { m_window->cleanup(); }

    void Window::pollEvents() { m_window->pollEvents(); }

    bool Window::shouldClose() const { return m_window->shouldClose(); }

    void Window::close() { m_window->close(); }

    bool Window::keyDown(const int p_keyCode) const { return m_window->getKeyIsDown(p_keyCode); }

    VkSurfaceKHR Window::getVulkanSurface(const VkInstance p_instance) const { return m_window->getVulkanSurface(p_instance); }

    unsigned int Window::getWidth() const { return m_window->getWidth(); }

    unsigned int Window::getHeight() const { return m_window->getHeight(); }
} // namespace wsky
