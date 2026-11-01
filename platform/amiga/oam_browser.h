/* oam_browser: opens a web address or a file in a browser (DESIGN.md 4).
 *
 * Tried in this order:
 *   1. ENV:GFOpenMail/Browser: a command, %s standing for the address (put
 *      in quotes; one with '"', '`', '*', '$' or control characters is not
 *      put on the line);
 *   2. AmiCradle's browser, on ARexx port AMICRADLE.BROWSER, with
 *      OPENURL address or OPENFILE path (reserved for that browser: once it
 *      answers there, GFOpenMail uses it with no change);
 *   3. openurl.library (OpenURL), which most Amiga browsers register with.
 * Sign-in pages (OAuth) and "View in browser" both come through here. */
#ifndef OAM_BROWSER_H
#define OAM_BROWSER_H

#include <stddef.h>

#define OAM_BROWSER_PORT "AMICRADLE.BROWSER"

/* what: a URL ("https://...", "mailto:...") or an AmigaDOS path to a file.
 * A link from a message goes through oam_link_for_browser first.
 * 1 when a browser took it, with how it was opened in how; 0 with the
 * reason in how. */
int oam_browser_open(const char *what, char *how, size_t howlen);

#endif
