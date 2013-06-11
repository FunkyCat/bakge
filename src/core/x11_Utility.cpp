/* *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2013 Paul Holden et al. (See AUTHORS)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * */

#include <bakge/Bakge.h>

namespace bakge
{

Result Init(int argc, char* argv[])
{
    /* Connect to X server */
    x11_Window::XDisplay = XOpenDisplay(NULL);
    if(x11_Window::XDisplay == NULL) {
        printf("Unable to connect to X server\n");
        return BGE_FAILURE;
    }

    /* Check if X server has GLX extension */
    if(glXQueryExtension(x11_Window::XDisplay, NULL, NULL) == False) {
        printf("X server has no GLX extension\n");
        return BGE_FAILURE;
    }

    /* Create window close event atom */
    x11_Window::CloseProtocol = XInternAtom(x11_Window::XDisplay,
                                        "WM_DELETE_WINDOW", True);

    return BGE_FAILURE;
}


Result Deinit()
{
    /* Close X server connection */
    if(x11_Window::XDisplay != NULL) {
        XCloseDisplay(x11_Window::XDisplay);
    }

    return BGE_FAILURE;
}

} /* bakge */
