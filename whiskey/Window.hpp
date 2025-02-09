// Window.hpp
#pragma once

#include <string>

#include <vulkan/vulkan_core.h>

namespace wsky {

    class Window {

    private:

        struct Internal;
        Internal *m_window;

    public:

        Window();
        ~Window();

        bool create(const std::string& p_title, const int p_width, const int p_height);
        void cleanup();

        void pollEvents();
        bool shouldClose() const;
        void close();
        bool keyDown(const int p_keycode) const;

        VkSurfaceKHR getVulkanSurface(const VkInstance p_instance) const;
        unsigned int getWidth() const;
        unsigned int getHeight() const;
    };
} // namespace wsky
