/**
 * @file      BearLibTerminal.h
 * @copyright MIT License
 * @author    Cfyz
 * @date      Tue Dec 11 10:37:48 2018
 * @brief     C/C++ header for BearLibTerminal library
 */

/*
* BearLibTerminal
* Copyright (C) 2013-2017 Cfyz
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
* of the Software, and to permit persons to whom the Software is furnished to do
* so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
* FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
* COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
* IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/**
 * @mainpage BearLibTerminal Documentation
 *
 * @section intro_sec Introduction
 *
 * This documentation will give you a reference of the library APIs.
 *   - <a href="http://foo.wyrd.name/en:bearlibterminal:design">Overview of the library</a>
 *   - @link BearLibTerminal.h Reference @endlink
 *     - @ref scancodes Keyboard scan codes
 *     - @ref mouse_events_states Mouse events/states
 *     - @ref virtual_key_codes Virtual key codes
 *     - @ref other_events Other events
 *     - @ref mode_enum Generic mode enum
 *     - @ref input_result_codes Input result codes for terminal_read function
 *     - @ref text_alignment Text printing alignment
 *     - Data-structures:
 *       - ::color_t
 *       - ::dimensions_t
 *   - <a href="http://foo.wyrd.name/en:bearlibterminal:reference:input">Input data details</a>
 *   - <a href="http://foo.wyrd.name/en:bearlibterminal:reference:configuration">Set configuration
 *              details</a>
 *   - @link ::color_t API list @endlink
 *
 * Don't forget to look at log file (named <i>bearlibterminal.log</i> by
 * default).
 */

#ifndef BEARLIBTERMINAL_H
#define BEARLIBTERMINAL_H

#if defined(_MSC_VER) && !defined(_CRT_SECURE_NO_WARNINGS)
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifdef __GNUC__
#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ > 1)
#pragma GCC diagnostic ignored "-Wformat-nonliteral" /* False-positive when wrapping vsnprintf. */
#endif /* __GNUC__ >= 4.1 */
#endif

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>
#if defined(__cplusplus)
#include <sstream>
#endif

/**
 * @anchor scancodes
 * @name Keyboard scancodes for events/states
 * @{
 */
#define TK_A                0x04
#define TK_B                0x05
#define TK_C                0x06
#define TK_D                0x07
#define TK_E                0x08
#define TK_F                0x09
#define TK_G                0x0A
#define TK_H                0x0B
#define TK_I                0x0C
#define TK_J                0x0D
#define TK_K                0x0E
#define TK_L                0x0F
#define TK_M                0x10
#define TK_N                0x11
#define TK_O                0x12
#define TK_P                0x13
#define TK_Q                0x14
#define TK_R                0x15
#define TK_S                0x16
#define TK_T                0x17
#define TK_U                0x18
#define TK_V                0x19
#define TK_W                0x1A
#define TK_X                0x1B
#define TK_Y                0x1C
#define TK_Z                0x1D
#define TK_1                0x1E
#define TK_2                0x1F
#define TK_3                0x20
#define TK_4                0x21
#define TK_5                0x22
#define TK_6                0x23
#define TK_7                0x24
#define TK_8                0x25
#define TK_9                0x26
#define TK_0                0x27
#define TK_RETURN           0x28
#define TK_ENTER            0x28
#define TK_ESCAPE           0x29
#define TK_BACKSPACE        0x2A
#define TK_TAB              0x2B
#define TK_SPACE            0x2C
#define TK_MINUS            0x2D /**<  -  */
#define TK_EQUALS           0x2E /**<  =  */
#define TK_LBRACKET         0x2F /**<  [  */
#define TK_RBRACKET         0x30 /**<  ]  */
#define TK_BACKSLASH        0x31 /**<  \  */
#define TK_SEMICOLON        0x33 /**<  ;  */
#define TK_APOSTROPHE       0x34 /**<  '  */
#define TK_GRAVE            0x35 /**<  `  */
#define TK_COMMA            0x36 /**<  ,  */
#define TK_PERIOD           0x37 /**<  .  */
#define TK_SLASH            0x38 /**<  /  */
#define TK_F1               0x3A
#define TK_F2               0x3B
#define TK_F3               0x3C
#define TK_F4               0x3D
#define TK_F5               0x3E
#define TK_F6               0x3F
#define TK_F7               0x40
#define TK_F8               0x41
#define TK_F9               0x42
#define TK_F10              0x43
#define TK_F11              0x44
#define TK_F12              0x45
#define TK_PAUSE            0x48 /**< Pause/Break */
#define TK_INSERT           0x49
#define TK_HOME             0x4A
#define TK_PAGEUP           0x4B
#define TK_DELETE           0x4C
#define TK_END              0x4D
#define TK_PAGEDOWN         0x4E
#define TK_RIGHT            0x4F /**< Right arrow */
#define TK_LEFT             0x50 /**< Left arrow */
#define TK_DOWN             0x51 /**< Down arrow */
#define TK_UP               0x52 /**< Up arrow */
#define TK_KP_DIVIDE        0x54 /**< '/' on numpad */
#define TK_KP_MULTIPLY      0x55 /**< '*' on numpad */
#define TK_KP_MINUS         0x56 /**< '-' on numpad */
#define TK_KP_PLUS          0x57 /**< '+' on numpad */
#define TK_KP_ENTER         0x58
#define TK_KP_1             0x59
#define TK_KP_2             0x5A
#define TK_KP_3             0x5B
#define TK_KP_4             0x5C
#define TK_KP_5             0x5D
#define TK_KP_6             0x5E
#define TK_KP_7             0x5F
#define TK_KP_8             0x60
#define TK_KP_9             0x61
#define TK_KP_0             0x62
#define TK_KP_PERIOD        0x63 /**< '.' on numpad */
#define TK_SHIFT            0x70
#define TK_CONTROL          0x71
#define TK_ALT              0x72
/**
 * @}
 */

/**
 * @anchor mouse_events_states Mouse events/states
 * @name Mouse events/states
 * @{
 */
#define TK_MOUSE_LEFT       0x80 /**< Buttons */
#define TK_MOUSE_RIGHT      0x81
#define TK_MOUSE_MIDDLE     0x82
#define TK_MOUSE_X1         0x83
#define TK_MOUSE_X2         0x84
#define TK_MOUSE_MOVE       0x85 /**< Movement event */
#define TK_MOUSE_SCROLL     0x86 /**< Mouse scroll event */
#define TK_MOUSE_X          0x87 /**< Cusor position in cells */
#define TK_MOUSE_Y          0x88
#define TK_MOUSE_PIXEL_X    0x89 /**< Cursor position in pixels */
#define TK_MOUSE_PIXEL_Y    0x8A
#define TK_MOUSE_WHEEL      0x8B /**< Scroll direction and amount */
#define TK_MOUSE_CLICKS     0x8C /**< Number of consecutive clicks */
/**
 * @}
 */

/**
 * @def TK_KEY_RELEASED
 * If key was released instead of pressed, it's code will be OR'ed with TK_KEY_RELEASED:
 * a) pressed 'A': 0x04
 * b) released 'A': 0x04|VK_KEY_RELEASED = 0x104
 */
#define TK_KEY_RELEASED     0x100

/**
 * @anchor virtual_key_codes
 * @name Virtual key-codes for internal terminal states/variables.
 * These can be accessed via terminal_state function.
 * @{
 */
#define TK_WIDTH            0xC0 /**< Terminal window width in cells */
#define TK_HEIGHT           0xC1 /**< Terminal window height in cells */
#define TK_CELL_WIDTH       0xC2 /**< Character cell width in pixels */
#define TK_CELL_HEIGHT      0xC3 /**< Character cell height in pixels */
#define TK_COLOR            0xC4 /**< Current foregroung color */
#define TK_BKCOLOR          0xC5 /**< Current background color */
#define TK_LAYER            0xC6 /**< Current layer */
#define TK_COMPOSITION      0xC7 /**< Current composition state */
#define TK_CHAR             0xC8 /**< Translated ANSI code of last produced character */
#define TK_WCHAR            0xC9 /**< Unicode codepoint of last produced character */
#define TK_EVENT            0xCA /**< Last dequeued event */
#define TK_FULLSCREEN       0xCB /**< Fullscreen state */
/**
 * @}
 */

/**
 * @anchor other_events
 * @name Other events
 * @{
 */
#define TK_CLOSE            0xE0
#define TK_RESIZED          0xE1
/**
 * @}
 */

/**
 * @anchor mode_enum
 * @name Generic mode enum
 * Right now it is used for composition option only
 * @{
 */
#define TK_OFF                 0
#define TK_ON                  1
/**
 * @}
 */

/**
 * @anchor input_result_codes
 * @name Input result codes for terminal_read function.
 * @{
 */
#define TK_INPUT_NONE          0
#define TK_INPUT_CANCELLED    -1
/**
 * @}
 */

/**
 * @anchor text_alignment
 * @name Text printing alignment.
 * @{
 */
#define TK_ALIGN_DEFAULT       0
#define TK_ALIGN_LEFT          1
#define TK_ALIGN_RIGHT         2
#define TK_ALIGN_CENTER        3
#define TK_ALIGN_TOP           4
#define TK_ALIGN_BOTTOM        8
#define TK_ALIGN_MIDDLE       12
/**
 * @}
 */

/**
 * @typedef uint32_t color_t
 * Terminal uses unsigned 32-bit value for color representation in ARGB order (0xAARRGGBB), e. g.
 * a) solid red is 0xFFFF0000
 * b) half-transparent green is 0x8000FF00
 */
typedef uint32_t color_t;

/**
 * @struct dimensions_t
 * Generic structure to describe a dimension (width/height)
 */
typedef struct dimensions_t_
{
	int width;
	int height;
}
dimensions_t;

#if defined(BEARLIBTERMINAL_STATIC_BUILD)
#  define TERMINAL_API
#elif defined(_WIN32)
#  if defined(BEARLIBTERMINAL_BUILDING_LIBRARY)
#    define TERMINAL_API __declspec(dllexport)
#  else
#    define TERMINAL_API __declspec(dllimport)
#  endif
#else
#  if defined(BEARLIBTERMINAL_BUILDING_LIBRARY) && __GNUC__ >= 4
#    define TERMINAL_API __attribute__ ((visibility ("default")))
#  else
#    define TERMINAL_API
#  endif
#endif

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Initialize the library instance
 * @details This function initializes the library, configure the window with
 *          default parameters: 80x25 cells, Fixedsys Excelsior font,
 *          white text on a black background. This function does not bring the
 *          window to screen. The window is not shown until the first call to 
 *          terminal_refresh().
 * @return Boolean value, 0 on error, non-zero otherwise.
 * @note Unless the library is initialized with successful call to open, all
 *       other library functions will do nothing but return immediately with
 *       return code (if any) indicating an error.
 * @sa terminal_close()
 */
TERMINAL_API int terminal_open();

/**
 * @brief Close the library instance
 * @details Opposite to terminal_open(), closes the window and deinitializes
 *          BearLibTerminal instance.
 */
TERMINAL_API void terminal_close();

/**
 * @brief Configure library options and mechanics, managing fonts, tilesets and
 *        even configuration file is performed with it.
 * @details The function accepts a "configuration string" with various options
 *          described in it:
 * @verbatim
 window.title='game';
 font: UbuntuMono-R.ttf, size=12;
 ini.settings.tile-size=16;
 @endverbatim
 * @param[in] value The configurations string 
 * @return 
 * @note For an information about configuration string format, library options
 *      and overall function behavior, refer to the separate
 *      <a href="http://foo.wyrd.name/en:bearlibterminal:reference:configuration">configuration</a> page
 * @note This function accepts 8-bit char strings
 */
TERMINAL_API int terminal_set8(const int8_t* value);

/**
 * @brief Configure library options and mechanics, managing fonts, tilesets and
 *        even configuration file is performed with it.
 * @details The function accepts a "configuration string" with various options
 *          described in it:
 * @verbatim
 window.title='game';
 font: UbuntuMono-R.ttf, size=12;
 ini.settings.tile-size=16;
 @endverbatim
 * @param[in] value The configurations string 
 * @return 
 * @note For an information about configuration string format, library options
 *      and overall function behavior, refer to the separate
 *      <a href="http://foo.wyrd.name/en:bearlibterminal:reference:configuration">configuration</a> page
 * @note This function accepts 16-bit char strings
 */
TERMINAL_API int terminal_set16(const int16_t* value);

/**
 * @brief Configure library options and mechanics, managing fonts, tilesets and
 *        even configuration file is performed with it.
 * @details The function accepts a "configuration string" with various options
 *          described in it:
 * @verbatim
 window.title='game';
 font: UbuntuMono-R.ttf, size=12;
 ini.settings.tile-size=16;
 @endverbatim
 * @param[in] value The configurations string 
 * @return 
 * @note For an information about configuration string format, library options
 *      and overall function behavior, refer to the separate
 *      <a href="http://foo.wyrd.name/en:bearlibterminal:reference:configuration">configuration</a> page
 * @note This function accepts 32-bit char strings
 */
TERMINAL_API int terminal_set32(const int32_t* value);

/**
 * @brief This function commits the scene for output
 * @details BearLibTerminal does not draw to screen immediately until
 *          terminal_put() or terminal_print() are called. Instead, the scene is
 *          constructed off-screen in a double-buffered manner. If the contents
 *          of the window are destroyed for some reason (for example, the window
 *          has been obstructed and operating system asking it to refresh),
 *          BearLibTerminal redraws an already commited "frontbuffer" scene.
 *          Only when this refresh function is called, the modified scene will
 *          be actually brought to screen.
 * @note The first call to this function since library initialization will show
 *       the window on screen. Between the terminal_open() and first refresh
 *       calls, the window stays invisible.
 * @note This function also has the effect of redrawing the scene
 */
TERMINAL_API void terminal_refresh();

/**
 * @brief This function clears entire scene (all layers).
 *        It also sets background color of every cell to the currently selected
 *        background color.
 */
TERMINAL_API void terminal_clear();

/**
 * @brief This function clears a part of the currently selected layer.
 * @details When called on the first layer, it also sets background color of
 *          affected cells to the currently selected background color.
 * @param[in] x x-coordinate, from left to right
 * @param[in] y y-coordinate, from top to bottom
 * @param[in] w Width
 * @param[in] h Height
 * @sa terminal_layer()
 */
TERMINAL_API void terminal_clear_area(int x, int y, int w, int h);

/**
 * @brief This function sets a crop area of the current layer
 * @param[in] x x-coordinate of the area to crop, from left to right
 * @param[in] y y-coordinate of the area to crop, from top to bottom
 * @param[in] w Width
 * @param[in] h Height
 * @note Dimensions of the area are expressed in cells
 * @note Cropping is disabled either by setting area's width or height to zero
 *       or by clearing entire scene with terminal_clear()
 * @sa terminal_layer()
 */
TERMINAL_API void terminal_crop(int x, int y, int w, int h);

/**
 * @brief This function selects the current layer of character cells.
 * @details Only the first layer has background, for layers 1 and above the
 *          background color set by terminal_bkcolor() has no effect. Note that
 *          terminal_clear_area() only affects the current layer while
 *          terminal_clear() wipes the entire scene. Layers are useful for
 *          various reasons. One is that BearLibTerminal allows tiles bigger
 *          than one character cell. But the scene is drawn cell by cell in
 *          fixed left-to-right, top-to-bottom order. This makes imposible for
 *          the big tile to properly cover cells to the right and below because
 *          those will be drawn later. With layers the scene can be separated
 *          into several parts with strict Z-ordering between them. Another use
 *          of layers is to logically separate the scene. Layers can be cleared
 *          and updated independently, so one can place parts of the scene in
 *          separate layers and update them without touching the others
 *          (for example, animated dungeon level and static UI).
 * @param[in] index In range from 0 to 255 where 0 is the lowest (default)
 *            layer.
 * @note The current layer index can be read from TK_LAYER state slot
 * @sa terminal_state()
 */
TERMINAL_API void terminal_layer(int index);

/**
 * @brief This function sets the current foreground color which will be used by
 *        all output functions called later.
 * @details The ::color_t type is a 32-bit unsigned integer describing color in
 *          \b BGRA (0xAARRGGBB) format. This numeric color representation can
 *          be constructed directly or by color_from_argb() utility function.
 *          For most languages including C++ there is also an overloaded
 *          version taking color name as a string (see color_from_name()).
 * @param[in] color The new color to use
 * @note The numeric value of current foreground color can be retrieved by
 *       reading TK_COLOR state.
 */
TERMINAL_API void terminal_color(color_t color);

/**
 * @brief Similar to terminal_color(), this function sets the current background
 *        color. 
 * @param[in] color New background color
 * @note Only the first, lowest layer of cells has background
 * @note The numeric value of current background color can be retrieved by
 *       reading TK_BKCOLOR state, see terminal_state()
 */
TERMINAL_API void terminal_bkcolor(color_t color);

/**
 * @brief This function sets character composition mode
 * @details When composition is off, putting a tile in a cell (by
 *          terminal_put() or terminal_print()), simply replaces the contents of
 *          that cell. When composition is on, however, the tile is \b added to
 *          the cell's tile stack. This has visual effect of combining several
 *          tiles into one. There is no enforced limit to number of tiles in a
 *          single cell.
 * @param[in] mode Can be TK_OFF (default) or TK_ON
 * @note Each tile in the stack has its own foreground color and offset
 *       (see terminal_put_ext())
 * @note Current composition mode can be retrieved by reading the TK_COMPOSITION
 *       slot passed to terminal_state()
 */
TERMINAL_API void terminal_composition(int mode);

/**
 * @brief Set new font
 * @param[in] name The name of the new font. If empty or "main", the default
 *            font is used. If name is an invalid font name, no actions are
 *            performed
 * @note This function accepts 8-bit char strings
 */
TERMINAL_API void terminal_font8(const int8_t* name);

/**
 * @brief Set new font
 * @param[in] name The name of the new font. If empty or "main", the default
 *            font is used. If name is an invalid font name, no actions are
 *            performed
 * @note This function accepts 16-bit char strings
 */
TERMINAL_API void terminal_font16(const int16_t* name);

/**
 * @brief Set new font
 * @param[in] name The name of the new font. If empty or "main", the default
 *            font is used. If name is an invalid font name, no actions are
 *            performed
 * @note This function accepts 32-bit char strings
 */
TERMINAL_API void terminal_font32(const int32_t* name);

/**
 * @brief Puts a tile associated with the given character code into a cell
 * @param[in] x x-coordinate of the cell
 * @param[in] y y-coordinate of the cell
 * @param[in] code The caracter code to put, must be an Unicode code point
 * @note If the specified code is not associated with any tile, library use
 *       not-a-character tile with thin rectangle on it
 * @note Even if the currently selected font is a bitmap font with only a
 *       handful of tiles, BearLibTerminal internally maps those tiles to the
 *       proper Unicode code points
 * @note For example euro sign if present will always be available by code point
 *       <em>U+20AC</em> unless the library is misconfigured
 */
TERMINAL_API void terminal_put(int x, int y, int code);

/**
 * @brief It is an advanced version of terminal_put(), allowing to also specify
 *        the tile offset and paint tile corners in different colors
 * @details When using terminal_composition(), there may be more than one tile
 *          in a cell and each of them will have its own offset values.
 *          Note that offset does not change the drawing order in any way. Even
 *          if the tile is visually shifted to the right or below the cell it
 *          belongs to, it will be drawn in usual cell-by-cell order and may
 *          become covered by the other tiles. Use layers in that situation.
 * @param[in] x x-coordinate of the cell
 * @param[in] y y-coordinate of the cell
 * @param[in] dx x-coordinate of the tile offset in pixels relative to the
 *               normal position of that tile in a cell
 * @param[in] dy y-coordinate of the tile offset in pixels relative to the
 *               normal position of that tile in a cell
 * @param[in] code The caracter code to put, must be an Unicode code point
 * @param[in] corners An array of four color_t values describing individual
 *            colors of tile corners in the following order:
 *            top-left, bottom-left, bottom-right, top right
 *            (counter-clockwise starting from top-left).\n
 *            This feature allows smooth gradients and transitions between
 *            tiles. As with offset values, each tile in a cell has its own
 *            corner colors.\n
 *            If NULL is passed as the corners parameter, the current
 *            foreground color is used
 */
TERMINAL_API void terminal_put_ext(int x, int y, int dx, int dy, int code, color_t* corners);

/**
 * @brief Returns the code of a symbol/tile in the specified cell of the current
 *        layer
 * @param[in] x x-coordinate of the cell
 * @param[in] y y-coordinate of the cell
 * @param[in] index The index of the tile in the cell
 * @return The queried code or zero
 * @note The function does a reverse codepage translation of a tile code
 *       in accordance to terminal.encoding option
 */
TERMINAL_API int terminal_pick(int x, int y, int index);

/**
 * @brief Returns the color of a tile in the specified cell
 * @param[in] x x-coordinate of the cell
 * @param[in] y y-coordinate of the cell
 * @param[in] index The index of the tile in the cell
 * @return The queried color
 */
TERMINAL_API color_t terminal_pick_color(int x, int y, int index);

/**
 * @brief Returns the background color of the specified cell
 * @param[in] x x-coordinate of the cell
 * @param[in] y y-coordinate of the cell
 * @return The queried color
 */
TERMINAL_API color_t terminal_pick_bkcolor(int x, int y);

/**
 * @brief Prints a string starting from given coordinates, with optional
 *        auto-wrapping and alignment
 * @details Behavior of print function may be modified by a number of tags in
 *          the string:
 *          - Foreground and background colors: [color=red] or [bkcolor=gray].
 *            Color names are parsed by color_from_name() function
 *          - Arbitrary character codes: [U+E001] or [0xE001]
 *          - Symbol combining: a[+]^ will produce something similar to â.
 *            Combining is done as if by placing two tiles into single cell with
 *            terminal_composition() enabled
 *          - Pixel offset: [offset=4,8]. This adds an offset to every character
 *            placed by print, as if they were printed by terminal_put_ext()
 *            function
 *          - Font change: [font=somename]. Enables output in
 *            <a href="http://foo.wyrd.name/en:bearlibterminal:reference:configuration#font_and_tileset_management">additional font faces</a>
 *
 *          Colors, pixel offset and font shift can be canceled by placing a
 *          symmetric closing tag, e. g. <em>[/color]</em> or <em>[/offset]</em>
 *          Note that these are simple set/reset commands and they cannot be
 *          truly nested. There is no need to manually cancel every tag
 *          mentioned in a string because all of the effects are local to a
 *          single terminal_print() call\n\n
 *          Example:
 *          @code{.c} terminal_printf("[offset=%d,%d]g[+][color=red]^[/color] (red-hooded goblin)", dx, dy); @endcode
 *
 * @param[in] x x-coordinate of the cell
 * @param[in] y y-coordinate of the cell
 * @param[in] w Wrapping width
 * @param[in] h Wrapping height
 * @param[in] align May be one or a combination of:
 *                  - TK_ALIGN_DEFAULT (top-left)
 *                  - TK_ALIGN_LEFT
 *                  - TK_ALIGN_RIGHT
 *                  - TK_ALIGN_CENTER (center horizontally)
 *                  - TK_ALIGN_TOP
 *                  - TK_ALIGN_BOTTOM
 *                  - TK_ALIGN_MIDDLE (center vertically)
 * @param[in] s The string to print, see also terminal_print_ext16() and
 *              terminal_print_ext32()
 * @param[out] out_w If not NULL, will receive the printed string width
 * @param[out] out_h If not NULL, will receive the printed string height
 * @note Each individual symbol is placed separately as if by calling
 *       terminal_put() or terminal_put_ext() (i.e.: print takes full advantage
 *       of selected terminal_color(), terminal_layer() and
 *       terminal_composition() options
 * @note To print a single [ or ] bracket, just double it
 */
TERMINAL_API void terminal_print_ext8(int x, int y, int w, int h, int align, const int8_t* s, int* out_w, int* out_h);

/** The same as terminal_print_ext8(), but accepts 16-bit chars string */
TERMINAL_API void terminal_print_ext16(int x, int y, int w, int h, int align, const int16_t* s, int* out_w, int* out_h);

/** The same as terminal_print_ext8(), but accepts 32-bit chars string */
TERMINAL_API void terminal_print_ext32(int x, int y, int w, int h, int align, const int32_t* s, int* out_w, int* out_h);

/**
 * @brief This function returns the size of a string if it would have printed
 *        on screen
 * @details w/h specify the box delimiting the auto-wrapped string
 * @param[in] w Delimiting box width
 * @param[in] h Delimiting box height
 * @param[in] s The string to measure
 * @param[out] out_w The measured width
 * @param[out] out_h The measured height
 * @note Unlike print_ext() and similar, there is no alignment argument, since
 *       it does not affect the size
 * @note This function accepts string in 8-bit char format
 */
TERMINAL_API void terminal_measure_ext8(int w, int h, const int8_t* s, int* out_w, int* out_h);

/**
 * @brief This function returns the size of a string if it would have printed
 *        on screen
 * @details w/h specify the box delimiting the auto-wrapped string
 * @param[in] w Delimiting box width
 * @param[in] h Delimiting box height
 * @param[in] s The string to measure
 * @param[out] out_w The measured width
 * @param[out] out_h The measured height
 * @note Unlike print_ext() and similar, there is no alignment argument, since
 *       it does not affect the size
 * @note This function accepts string in 16-bit char format
 */
TERMINAL_API void terminal_measure_ext16(int w, int h, const int16_t* s, int* out_w, int* out_h);

/**
 * @brief This function returns the size of a string if it would have printed
 *        on screen
 * @details w/h specify the box delimiting the auto-wrapped string
 * @param[in] w Delimiting box width
 * @param[in] h Delimiting box height
 * @param[in] s The string to measure
 * @param[out] out_w The measured width
 * @param[out] out_h The measured height
 * @note Unlike print_ext() and similar, there is no alignment argument, since
 *       it does not affect the size
 * @note This function accepts string in 32-bit char format
 */
TERMINAL_API void terminal_measure_ext32(int w, int h, const int32_t* s, int* out_w, int* out_h);

/**
 * @brief This function tells about input availability
 * @return true (non-zero) means that next read call will return a value
 *         without blocking. False (zero) otherwise
 */
TERMINAL_API int terminal_has_input();

/**
 * @brief This function returns the current value of the state slot
 * @details These slots represent the library state: current foreground color,
 *          number of rows or columns, size of a cell, whether the key is
 *          pressed or not, etc. Most of the states are updated only by reading
 *          input events with terminal_read() function.  These states are kept
 *          consistent to each other, e. g. this key combination check will work
 *          correctly even if the keys are long released:
 * @code{.c}
 * int key = terminal_read();
 *  
 * if (key == TK_A)
 * {
 *     if (terminal_state(TK_SHIFT))
 *     {
 *         // Shift+A
 *     }
 *     else
 *     {
 *         // Just A
 *     }
 * }
 * @endcode
 * The state function and input queue are described in greater detail on the
 * separate page about input. There is also a list of all properties that can be
 * retieved with the state function on that page.
 * @param[in] code description
 * @return The state of specified slot
 */
TERMINAL_API int terminal_state(int code);

/**
 * @brief This function returns the next event from input queue.
 * @details If the queue is empty, read will wait for an event to come.
 *          If this blocking behaviour is not desirable, you can check if there
 *          is some input calling terminal_has_input()
 * @return The event code
 */
TERMINAL_API int terminal_read();

/**
 * @brief This function does a simple blocking read of a string without any
 *        parsing
 * @details User input is displayed at specified coordinates and also limited to
 *          specified length so it can be used in game interface.
 *          The function displays user input within current layer and restores
 *          the scene before return. It is an application's responsibility to
 *          keep the result on screen.
 * @param[in] x x-coordinate of position of obtained string to write
 * @param[in] y y-coordinate of position of obtained string to write
 * @param[out] buffer Pointer to buffer that will receive the read string
 * @param[in] max Maximum length of the printed string
 * @return The function returns the size of a string if user has confirmed input
 *         by pressing \b ENTER, or \b TK_INPUT_CANCELLED if operation was
 *         cancelled by pressing \b ESCAPE or closing the window
 * @note If read_str does not fit your needs, see
 *       <a href="http://foo.wyrd.name/en:bearlibterminal:reference:input#tk_char_tk_wchar_states">
 *       TK CHAR/TK WCHAR</a> states allowing for manual text input
 * @note This function receive string in a 8-bit char buffer
 */
TERMINAL_API int terminal_read_str8(int x, int y, int8_t* buffer, int max);

/**
 * @brief This function does a simple blocking read of a string without any
 *        parsing
 * @details User input is displayed at specified coordinates and also limited to
 *          specified length so it can be used in game interface.
 *          The function displays user input within current layer and restores
 *          the scene before return. It is an application's responsibility to
 *          keep the result on screen.
 * @param[in] x x-coordinate of position of obtained string to write
 * @param[in] y y-coordinate of position of obtained string to write
 * @param[out] buffer Pointer to buffer that will receive the read string
 * @param[in] max Maximum length of the printed string
 * @return The function returns the size of a string if user has confirmed input
 *         by pressing \b ENTER, or \b TK_INPUT_CANCELLED if operation was
 *         cancelled by pressing \b ESCAPE or closing the window
 * @note If read_str does not fit your needs, see
 *       <a href="http://foo.wyrd.name/en:bearlibterminal:reference:input#tk_char_tk_wchar_states">
 *       TK CHAR/TK WCHAR</a> states allowing for manual text input
 * @note This function receive string in a 16-bit char buffer
 */
TERMINAL_API int terminal_read_str16(int x, int y, int16_t* buffer, int max);

/**
 * @brief This function does a simple blocking read of a string without any
 *        parsing
 * @details User input is displayed at specified coordinates and also limited to
 *          specified length so it can be used in game interface.
 *          The function displays user input within current layer and restores
 *          the scene before return. It is an application's responsibility to
 *          keep the result on screen.
 * @param[in] x x-coordinate of position of obtained string to write
 * @param[in] y y-coordinate of position of obtained string to write
 * @param[out] buffer Pointer to buffer that will receive the read string
 * @param[in] max Maximum length of the printed string
 * @return The function returns the size of a string if user has confirmed input
 *         by pressing \b ENTER, or \b TK_INPUT_CANCELLED if operation was
 *         cancelled by pressing \b ESCAPE or closing the window
 * @note If read_str does not fit your needs, see
 *       <a href="http://foo.wyrd.name/en:bearlibterminal:reference:input#tk_char_tk_wchar_states">
 *       TK CHAR/TK WCHAR</a> states allowing for manual text input
 * @note This function receive string in a 32-bit char buffer
 */
TERMINAL_API int terminal_read_str32(int x, int y, int32_t* buffer, int max);

/**
 * @brief Return next event \b without removing it from queue
 * @details The next peek or read call will return the same value
 * @return The next event code
 * @note This is non-blocking function
 * @note If the queue is empty, it will not wait and return 0
 */
TERMINAL_API int terminal_peek();

/**
 * @brief Suspend program execution for specified time
 * @param[in] period Number of \b milliseconds to wait
 */
TERMINAL_API void terminal_delay(int period);

/**
 * @brief This function retrieves the value of an option (a library option or a
 *        property from the configuration file). If no such option is available,
 *        the supplied default value is returned
 * @details For details see <a href="http://foo.wyrd.name/en:bearlibterminal:reference:configuration">
 *          configuration</a> page. This function works on 8-bit chars
 * @param[in] key key/property description
 * @param[in] default_ Returned value if unavailable option
 * @return The desired configuration settings
 */
TERMINAL_API const int8_t* terminal_get8(const int8_t* key, const int8_t* default_);

/**
 * @brief This function retrieves the value of an option (a library option or a
 *        property from the configuration file). If no such option is available,
 *        the supplied default value is returned
 * @details For details see <a href="http://foo.wyrd.name/en:bearlibterminal:reference:configuration">
 *          configuration</a> page. This function works on 16-bit chars
 * @param[in] key key/property description
 * @param[in] default_ Returned value if unavailable option
 * @return The desired configuration settings
 */
TERMINAL_API const int16_t* terminal_get16(const int16_t* key, const int16_t* default_);

/**
 * @brief This function retrieves the value of an option (a library option or a
 *        property from the configuration file). If no such option is available,
 *        the supplied default value is returned
 * @details For details see <a href="http://foo.wyrd.name/en:bearlibterminal:reference:configuration">
 *          configuration</a> page. This function works on 32-bit chars
 * @param[in] key key/property description
 * @param[in] default_ Returned value if unavailable option
 * @return The desired configuration settings
 */
TERMINAL_API const int32_t* terminal_get32(const int32_t* key, const int32_t* default_);

/**
 * @brief This function returns a numeric representation of a color from palette
 * @details The name is spelled in "[brightness ]hue" form, e. g. "red",
 *          "light green", "darker #905025".\n Possible values for brightness are:
 *          lightest, lighter, light, dark, darker, darkest\n
 *          Hue (base color) may be specified in a number of ways:
 *          - By name: grey (or gray), red, flame, orange, amber, yellow, lime,
 *            chartreuse, green, sea, turquoise, cyan, sky, azure, blue, han,
 *            violet, purple, fuchsia, magenta, pink, crimson, transparent
 *          - In a hexadecimal format: \#RRGGBB or \#AARRGGBB, e.g. \#80905025
 *          - In a comma-separated decimal format: R,G,B or A,R,G,B
 *            e.g. 128,200,150,75
 *          - As a plain integer number formatted to a string, e.g. 16744448
 *
 * @param[in] name The color string
 * @return The desired color or white if null/empty/errors
 * @note New named colors may be added to the default palette by calling
 *       terminal_set() ex.: @code{.c} 
 *       terminal_set("palette.octarine = #50FF25"); @endcode
 *       or in a configuration file:
 * @verbatim
[Palette]
lush = dark 80,255,37
@endverbatim
 * Note that terminal_print() uses this function to parse the values of its
 * color formatting tags
 * @note This function take a 8-bit char string
 */
TERMINAL_API color_t color_from_name8(const int8_t* name);

/**
 * @brief This function returns a numeric representation of a color from palette
 * @details The name is spelled in "[brightness ]hue" form, e. g. "red",
 *          "light green", "darker #905025".\n Possible values for brightness are:
 *          lightest, lighter, light, dark, darker, darkest\n
 *          Hue (base color) may be specified in a number of ways:
 *          - By name: grey (or gray), red, flame, orange, amber, yellow, lime,
 *            chartreuse, green, sea, turquoise, cyan, sky, azure, blue, han,
 *            violet, purple, fuchsia, magenta, pink, crimson, transparent
 *          - In a hexadecimal format: \#RRGGBB or \#AARRGGBB, e.g. \#80905025
 *          - In a comma-separated decimal format: R,G,B or A,R,G,B
 *            e.g. 128,200,150,75
 *          - As a plain integer number formatted to a string, e.g. 16744448
 *
 * @param[in] name The color string
 * @return The desired color or white if null/empty/errors
 * @note New named colors may be added to the default palette by calling
 *       terminal_set() ex.: @code{.c} 
 *       terminal_set("palette.octarine = #50FF25"); @endcode
 *       or in a configuration file:
 * @verbatim
[Palette]
lush = dark 80,255,37
@endverbatim
 * Note that terminal_print() uses this function to parse the values of its
 * color formatting tags
 * @note This function take a 16-bit char string
 */
TERMINAL_API color_t color_from_name16(const int16_t* name);

/**
 * @brief This function returns a numeric representation of a color from palette
 * @details The name is spelled in "[brightness ]hue" form, e. g. "red",
 *          "light green", "darker #905025".\n Possible values for brightness are:
 *          lightest, lighter, light, dark, darker, darkest\n
 *          Hue (base color) may be specified in a number of ways:
 *          - By name: grey (or gray), red, flame, orange, amber, yellow, lime,
 *            chartreuse, green, sea, turquoise, cyan, sky, azure, blue, han,
 *            violet, purple, fuchsia, magenta, pink, crimson, transparent
 *          - In a hexadecimal format: \#RRGGBB or \#AARRGGBB, e.g. \#80905025
 *          - In a comma-separated decimal format: R,G,B or A,R,G,B
 *            e.g. 128,200,150,75
 *          - As a plain integer number formatted to a string, e.g. 16744448
 *
 * @param[in] name The color string
 * @return The desired color or white if null/empty/errors
 * @note New named colors may be added to the default palette by calling
 *       terminal_set() ex.: @code{.c} 
 *       terminal_set("palette.octarine = #50FF25"); @endcode
 *       or in a configuration file:
 * @verbatim
[Palette]
lush = dark 80,255,37
@endverbatim
 * Note that terminal_print() uses this function to parse the values of its
 * color formatting tags
 * @note This function take a 32-bit char string
 */
TERMINAL_API color_t color_from_name32(const int32_t* name);

#ifdef __cplusplus
} /* End of extern "C" */
#endif

#define TERMINAL_PRIMITIVE_CAT(a, b) a ## b
#define TERMINAL_CAT(a, b) TERMINAL_PRIMITIVE_CAT(a, b)

/*
 * wchar_t has different sized depending on platform. Furthermore, it's size
 * can be changed for GCC compiler.
 */
#if !defined(__SIZEOF_WCHAR_T__)
#  if defined(_WIN32)
#    define __SIZEOF_WCHAR_T__ 2
#  else
#    define __SIZEOF_WCHAR_T__ 4
#  endif
#endif

#if __SIZEOF_WCHAR_T__ == 2
#define TERMINAL_WCHAR_SUFFIX 16
#define TERMINAL_WCHAR_TYPE int16_t
#else // 4
#define TERMINAL_WCHAR_SUFFIX 32
#define TERMINAL_WCHAR_TYPE int32_t
#endif

#if defined(__cplusplus)
#define TERMINAL_INLINE inline
#define TERMINAL_DEFAULT(value) = value
#else
#define TERMINAL_INLINE static inline
#define TERMINAL_DEFAULT(value)
#endif

/*
 * These functions provide inline string formatting support
 * for terminal_setf, terminal_printf, etc.
 *
 * Using static termporary buffer is okay because terminal API is not
 * required to be multiple-thread safe by design.
 */

#define TERMINAL_VSPRINTF_MAXIMUM_BUFFER_SIZE 65536

TERMINAL_INLINE const char* terminal_vsprintf(const char* s, va_list args)
{
	static int buffer_size = 512;
	static char* buffer = NULL;
	int rc = 0;

	if (!s)
		return NULL;
	else if (!buffer)
		buffer = (char*)malloc(buffer_size);

	while (1)
	{
		buffer[buffer_size-1] = '\0';
		rc = vsnprintf(buffer, buffer_size, s, args);
		if (rc >= buffer_size || buffer[buffer_size-1] != '\0')
		{
			if (buffer_size >= TERMINAL_VSPRINTF_MAXIMUM_BUFFER_SIZE)
				return NULL;

			buffer_size *= 2;
			buffer = (char*)realloc(buffer, buffer_size);
		}
		else
		{
			break;
		}
	}

	return rc >= 0? buffer: NULL;
}

TERMINAL_INLINE const wchar_t* terminal_vswprintf(const wchar_t* s, va_list args)
{
	static int buffer_size = 512;
	static wchar_t* buffer = NULL;
	int rc = 0;

	if (!s)
		return NULL;
	else if (!buffer)
		buffer = (wchar_t*)malloc(buffer_size * sizeof(wchar_t));

	while (1)
	{
		buffer[buffer_size-1] = L'\0';
#if defined(_WIN32)
		rc = _vsnwprintf(buffer, buffer_size, s, args);
#else
		rc = vswprintf(buffer, buffer_size, s, args);
#endif
		if (rc >= buffer_size || buffer[buffer_size-1] != L'\0')
		{
			if (buffer_size >= TERMINAL_VSPRINTF_MAXIMUM_BUFFER_SIZE)
				return NULL;

			buffer_size *= 2;
			buffer = (wchar_t*)realloc(buffer, buffer_size * sizeof(wchar_t));
		}
		else
		{
			break;
		}
	}

	return rc >= 0? buffer: NULL;
}

#define TERMINAL_FORMATTED_WRAP(type, call) \
	type ret; \
	va_list args; \
	va_start(args, s); \
	ret = call; \
	va_end(args); \
	return ret;

#define TERMINAL_FORMATTED_WRAP_V(call) \
	va_list args; \
	va_start(args, s); \
	call; \
	va_end(args);

/*
 * This set of inline functions define basic name substitution + type cast:
 * terminal_[w]xxxx -> terminal_xxxx{8|16|32}
 */

/** @brief Just a wrapper of terminal_set8() */
TERMINAL_INLINE int terminal_set(const char* s)
{
	return terminal_set8((const int8_t*)s);
}

TERMINAL_INLINE int terminal_setf(const char* s, ...)
{
	TERMINAL_FORMATTED_WRAP(int, terminal_set(terminal_vsprintf(s, args)))
}

TERMINAL_INLINE int terminal_wset(const wchar_t* s)
{
	return TERMINAL_CAT(terminal_set, TERMINAL_WCHAR_SUFFIX)((const TERMINAL_WCHAR_TYPE*)s);
}

TERMINAL_INLINE int terminal_wsetf(const wchar_t* s, ...)
{
	TERMINAL_FORMATTED_WRAP(int, terminal_wset(terminal_vswprintf(s, args)))
}

/** @brief Just a wrapper of terminal_font8() */
TERMINAL_INLINE void terminal_font(const char* name)
{
	terminal_font8((const int8_t*)name);
}

TERMINAL_INLINE void terminal_wfont(const wchar_t* name)
{
	TERMINAL_CAT(terminal_font, TERMINAL_WCHAR_SUFFIX)((const TERMINAL_WCHAR_TYPE*)name);
}

/**
 * @brief Essentially a wrapper of terminal_print_ext8(), but return the printed
 *        size
 * @return the size of a string printed on the screen
 */
TERMINAL_INLINE dimensions_t terminal_print(int x, int y, const char* s)
{
	dimensions_t ret;
	terminal_print_ext8(x, y, 0, 0, TK_ALIGN_DEFAULT, (const int8_t*)s, &ret.width, &ret.height);
	return ret;
}

TERMINAL_INLINE dimensions_t terminal_printf(int x, int y, const char* s, ...)
{
	TERMINAL_FORMATTED_WRAP(dimensions_t, terminal_print(x, y, terminal_vsprintf(s, args)))
}

TERMINAL_INLINE dimensions_t terminal_wprint(int x, int y, const wchar_t* s)
{
	dimensions_t ret;
	TERMINAL_CAT(terminal_print_ext, TERMINAL_WCHAR_SUFFIX)(x, y, 0, 0, TK_ALIGN_DEFAULT, (const TERMINAL_WCHAR_TYPE*)s, &ret.width, &ret.height);
	return ret;
}

TERMINAL_INLINE dimensions_t terminal_wprintf(int x, int y, const wchar_t* s, ...)
{
	TERMINAL_FORMATTED_WRAP(dimensions_t, terminal_wprint(x, y, terminal_vswprintf(s, args)))
}

/** @brief Just a wrapper of terminal_print_ext8() */
TERMINAL_INLINE dimensions_t terminal_print_ext(int x, int y, int w, int h, int align, const char* s)
{
	dimensions_t ret;
	terminal_print_ext8(x, y, w, h, align, (const int8_t*)s, &ret.width, &ret.height);
	return ret;
}

TERMINAL_INLINE dimensions_t terminal_printf_ext(int x, int y, int w, int h, int align, const char* s, ...)
{
	TERMINAL_FORMATTED_WRAP(dimensions_t, terminal_print_ext(x, y, w, h, align, terminal_vsprintf(s, args)));
}

TERMINAL_INLINE dimensions_t terminal_wprint_ext(int x, int y, int w, int h, int align, const wchar_t* s)
{
	dimensions_t ret;
	TERMINAL_CAT(terminal_print_ext, TERMINAL_WCHAR_SUFFIX)(x, y, w, h, align, (const TERMINAL_WCHAR_TYPE*)s, &ret.width, &ret.height);
	return ret;
}

TERMINAL_INLINE dimensions_t terminal_wprintf_ext(int x, int y, int w, int h, int align, const wchar_t* s, ...)
{
	TERMINAL_FORMATTED_WRAP(dimensions_t, terminal_wprint_ext(x, y, w, h, align, terminal_vswprintf(s, args)))
}

/** @brief Just a wrapper of terminal_measure_ext8() */
TERMINAL_INLINE dimensions_t terminal_measure(const char* s)
{
	dimensions_t ret;
	terminal_measure_ext8(0, 0, (const int8_t*)s, &ret.width, &ret.height);
	return ret;
}

TERMINAL_INLINE dimensions_t terminal_measuref(const char* s, ...)
{
	TERMINAL_FORMATTED_WRAP(dimensions_t, terminal_measure(terminal_vsprintf(s, args)))
}

TERMINAL_INLINE dimensions_t terminal_wmeasure(const wchar_t* s)
{
	dimensions_t ret;
	TERMINAL_CAT(terminal_measure_ext, TERMINAL_WCHAR_SUFFIX)(0, 0, (const TERMINAL_WCHAR_TYPE*)s, &ret.width, &ret.height);
	return ret;
}

TERMINAL_INLINE dimensions_t terminal_wmeasuref(const wchar_t* s, ...)
{
	TERMINAL_FORMATTED_WRAP(dimensions_t, terminal_wmeasure(terminal_vswprintf(s, args)))
}

TERMINAL_INLINE dimensions_t terminal_measure_ext(int w, int h, const char* s)
{
	dimensions_t ret;
	terminal_measure_ext8(w, h, (const int8_t*)s, &ret.width, &ret.height);
	return ret;
}

TERMINAL_INLINE dimensions_t terminal_measuref_ext(int w, int h, const char* s, ...)
{
	TERMINAL_FORMATTED_WRAP(dimensions_t, terminal_measure_ext(w, h, terminal_vsprintf(s, args)))
}

TERMINAL_INLINE dimensions_t terminal_wmeasure_ext(int w, int h, const wchar_t* s)
{
	dimensions_t ret;
	TERMINAL_CAT(terminal_measure_ext, TERMINAL_WCHAR_SUFFIX)(w, h, (const TERMINAL_WCHAR_TYPE*)s, &ret.width, &ret.height);
	return ret;
}

TERMINAL_INLINE dimensions_t terminal_wmeasuref_ext(int w, int h, const wchar_t* s, ...)
{
	TERMINAL_FORMATTED_WRAP(dimensions_t, terminal_wmeasure_ext(w, h, terminal_vswprintf(s, args)))
}

TERMINAL_INLINE int terminal_read_str(int x, int y, char* buffer, int max)
{
	return terminal_read_str8(x, y, (int8_t*)buffer, max);
}

TERMINAL_INLINE int terminal_read_wstr(int x, int y, wchar_t* buffer, int max)
{
	return TERMINAL_CAT(terminal_read_str, TERMINAL_WCHAR_SUFFIX)(x, y, (TERMINAL_WCHAR_TYPE*)buffer, max);
}

TERMINAL_INLINE const char* terminal_get(const char* key, const char* default_ TERMINAL_DEFAULT((const char*)0))
{
	return (const char*)terminal_get8((const int8_t*)key, (const int8_t*)default_);
}

TERMINAL_INLINE const wchar_t* terminal_wget(const wchar_t* key, const wchar_t* default_ TERMINAL_DEFAULT((const wchar_t*)0))
{
	return (const wchar_t*)TERMINAL_CAT(terminal_get, TERMINAL_WCHAR_SUFFIX)((const TERMINAL_WCHAR_TYPE*)key, (const TERMINAL_WCHAR_TYPE*)default_);
}

TERMINAL_INLINE color_t color_from_name(const char* name)
{
	return color_from_name8((const int8_t*)name);
}

TERMINAL_INLINE color_t color_from_wname(const wchar_t* name)
{
	return TERMINAL_CAT(color_from_name, TERMINAL_WCHAR_SUFFIX)((const TERMINAL_WCHAR_TYPE*)name);
}

#ifdef __cplusplus
/*
 * C++ supports function overloading, should take advantage of it.
 */

TERMINAL_INLINE int terminal_set(const wchar_t* s)
{
	return terminal_wset(s);
}

TERMINAL_INLINE int terminal_setf(const wchar_t* s, ...)
{
	TERMINAL_FORMATTED_WRAP(int, terminal_wset(terminal_vswprintf(s, args)));
}

TERMINAL_INLINE void terminal_color(const char* name)
{
	terminal_color(color_from_name(name));
}

TERMINAL_INLINE void terminal_color(const wchar_t* name)
{
	terminal_color(color_from_wname(name));
}

TERMINAL_INLINE void terminal_bkcolor(const char* name)
{
	terminal_bkcolor(color_from_name(name));
}

TERMINAL_INLINE void terminal_bkcolor(const wchar_t* name)
{
	terminal_bkcolor(color_from_wname(name));
}

TERMINAL_INLINE void terminal_font(const wchar_t* name)
{
	terminal_wfont(name);
}

TERMINAL_INLINE void terminal_put_ext(int x, int y, int dx, int dy, int code)
{
	terminal_put_ext(x, y, dx, dy, code, 0);
}

TERMINAL_INLINE dimensions_t terminal_print(int x, int y, const wchar_t* s)
{
	return terminal_wprint(x, y, s);
}

TERMINAL_INLINE dimensions_t terminal_printf(int x, int y, const wchar_t* s, ...)
{
	TERMINAL_FORMATTED_WRAP(dimensions_t, terminal_wprint(x, y, terminal_vswprintf(s, args)))
}

TERMINAL_INLINE dimensions_t terminal_print_ext(int x, int y, int w, int h, int align, const wchar_t* s)
{
	return terminal_wprint_ext(x, y, w, h, align, s);
}

TERMINAL_INLINE dimensions_t terminal_printf_ext(int x, int y, int w, int h, int align, const wchar_t* s, ...)
{
	TERMINAL_FORMATTED_WRAP(dimensions_t, terminal_wprint_ext(x, y, w, h, align, terminal_vswprintf(s, args)))
}

TERMINAL_INLINE dimensions_t terminal_measure(const wchar_t* s)
{
	return terminal_wmeasure(s);
}

TERMINAL_INLINE dimensions_t terminal_measuref(const wchar_t* s, ...)
{
	TERMINAL_FORMATTED_WRAP(dimensions_t, terminal_wmeasure(terminal_vswprintf(s, args)))
}

TERMINAL_INLINE dimensions_t terminal_measure_ext(int w, int h, const wchar_t* s)
{
	return terminal_wmeasure_ext(w, h, s);
}

TERMINAL_INLINE dimensions_t terminal_measuref_ext(int w, int h, const wchar_t* s, ...)
{
	TERMINAL_FORMATTED_WRAP(dimensions_t, terminal_wmeasure_ext(w, h, terminal_vswprintf(s, args)))
}

TERMINAL_INLINE int terminal_read_str(int x, int y, wchar_t* buffer, int max)
{
	return terminal_read_wstr(x, y, buffer, max);
}

TERMINAL_INLINE color_t color_from_name(const wchar_t* name)
{
	return color_from_wname(name);
}

TERMINAL_INLINE int terminal_pick(int x, int y)
{
	return terminal_pick(x, y, 0);
}

TERMINAL_INLINE color_t terminal_pick_color(int x, int y)
{
	return terminal_pick_color(x, y, 0);
}

TERMINAL_INLINE const wchar_t* terminal_get(const wchar_t* key, const wchar_t* default_ = (const wchar_t*)0)
{
	return terminal_wget(key, default_);
}

template<typename T, typename C> T terminal_get(const C* key, const T& default_ = T())
{
	const C* result_str = terminal_get(key, (const C*)0);
	if (result_str[0] == C(0))
		return default_;
	T result;
	return (bool)(std::basic_istringstream<C>(result_str) >> result)? result: default_;
}

#endif /* __cplusplus */

/*
 * Color routines
 */
TERMINAL_INLINE color_t color_from_argb(uint8_t a, uint8_t r, uint8_t g, uint8_t b)
{
	return ((color_t)a << 24) | (r << 16) | (g << 8) | b;
}

/*
 * Other functional sugar
 */
TERMINAL_INLINE int terminal_check(int code)
{
	return terminal_state(code) > 0;
}

/*
 * WinMain entry point handling macro. This allows easier entry point definition.
 * The macro will expand to proper WinMain stub regardless of header include order.
 */
#if defined(_WIN32)

/*
 * WinMain probe macro. It will expand to either X or X_WINDOWS_ depending on
 * Windows.h header inclusion.
 */
#define TERMINAL_TAKE_CARE_OF_WINMAIN TERMINAL_WINMAIN_PROBE_IMPL(_WINDOWS_)
#define TERMINAL_WINMAIN_PROBE_IMPL(DEF) TERMINAL_PRIMITIVE_CAT(TERMINAL_WINMAIN_IMPL, DEF)

/*
 * Trivial no-arguments WinMain implementation. It just calls main.
 */
#define TERMINAL_WINMAIN_IMPL_BASE(INSTANCE_T, STRING_T)\
	extern "C" int main();\
	extern "C" int __stdcall WinMain(INSTANCE_T hInstance, INSTANCE_T hPrevInstance, STRING_T lpCmdLine, int nCmdShow)\
	{\
		return main();\
	}

/*
 * Macro expands to empty string. Windows.h is included thus code MUST use
 * predefined types or else MSVC will complain.
 */
#define TERMINAL_WINMAIN_IMPL TERMINAL_WINMAIN_IMPL_BASE(HINSTANCE, LPSTR)

/*
 * Macro expands to macro name. Windows.h wasn't included, so WinMain will be
 * defined with fundamental types (enough for linker to find it).
 */
#define TERMINAL_WINMAIN_IMPL_WINDOWS_ TERMINAL_WINMAIN_IMPL_BASE(void*, char*)

#else

/*
 * Only Windows has WinMain but macro still must be defined for cross-platform
 * applications.
 */
#define TERMINAL_TAKE_CARE_OF_WINMAIN

#endif

#endif // BEARLIBTERMINAL_H
