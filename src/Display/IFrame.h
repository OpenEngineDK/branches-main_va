// Generic frame interface.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _INTERFACE_FRAME_H_
#define _INTERFACE_FRAME_H_

#include <Core/IModule.h>

namespace OpenEngine {
namespace Display {

using OpenEngine::Core::IModule;

/**
 * Frame options.
 *
 * @enum FrameOption
 */
enum FrameOption {
    FRAME_OPENGL     = 0x00000002,
    FRAME_NOBORDER   = 0x00000020,
    FRAME_FULLSCREEN = 0x80000000
};

/**
 * Frame module interface.
 *
 * @class IFrame IFrame.h Display/IFrame.h
 */
class IFrame : public virtual IModule {

public:

    /**
     * Frame constructor.
     *
     * @param w Frame width
     * @param h Frame height
     * @param d Frame depth
     * @param o Frame options
     */
    IFrame(int w, int h, int d, FrameOption o) {};

    /**
     * Frame destructor.
     */
    virtual ~IFrame() {};

    //! Test for type membership. @see EModule::IsTypeOf()
    bool IsTypeOf(const std::type_info& inf) { 
        return typeid(IFrame) == inf; 
    }

    /**
     * Is this frame focused.
     *
     * @return True if in focus.
     */
    virtual bool IsFocused() const = 0;
    
    /**
     * Get frame width.
     *
     * @return Frame width
     */
    virtual int GetWidth() const = 0;

    /**
     * Get frame height.
     *
     * @return Frame height
     */
    virtual int GetHeight() const = 0;
    
    /**
     * Get frame depth.
     *
     * @return Frame depth
     */
    virtual int GetDepth() const = 0;

    /**
     * Get frame options
     *
     * @return Frame options
     */
    virtual FrameOption GetOptions() const = 0;

    /**
     * Set frame width.
     * Must be supported as long as the module initialization method
     * has not been invoked.
     * After initialization the behavior is up to the implementation.
     *
     * @param width Frame width
     */
    virtual void SetWidth(const int width) = 0;

    /**
     * Set frame height.
     * Must be supported as long as the module initialization method
     * has not been invoked.
     * After initialization the behavior is up to the implementation.
     *
     * @param height Frame height
     */
    virtual void SetHeight(const int height) = 0;
    
    /**
     * Set frame depth.
     * Must be supported as long as the module initialization method
     * has not been invoked.
     * After initialization the behavior is up to the implementation.
     *
     * @param depth Frame depth
     */
    virtual void SetDepth(const int depth) = 0;

    /**
     * Set frame options
     * Must be supported as long as the module initialization method
     * has not been invoked.
     * After initialization the behavior is up to the implementation.
     *
     * @return options Frame options
     */
    virtual void SetOptions(const FrameOption options) = 0;

    /**
     * Check if an option is set.
     *
     * @param o Frame option(s) to check
     * @return True if set
     */
    bool IsOptionSet(const FrameOption o) const {
        return (o & GetOptions()) == o;
    }

};

} // NS Display
} // NS OpenEngine

#endif // _INTERFACE_FRAME_H_
