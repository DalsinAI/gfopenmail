/* oam_html: an HTML part as text, for the message view.
 *
 * Paragraphs, line breaks, headings and list items keep their shape; links
 * become "text [n]" with the n-th address added to links (one per line);
 * images become their alt text; head, script and style are dropped;
 * <pre> keeps its spacing; entities are decoded. Nothing is fetched: the
 * light view never reaches the network. The text is UTF-8, as the HTML
 * was (the caller converts the part's charset first). */
#ifndef OAM_HTML_H
#define OAM_HTML_H

#include <stddef.h>
#include "oam_buf.h"

/* 1, or 0 when memory ran out (what was made is kept). */
int oam_html_to_text(const char *html, size_t len, oam_buf *text, oam_buf *links);

/* A link from a message, checked before a browser gets it (and with it an
 * AmigaDOS command line, when ENV:GFOpenMail/Browser is set). 1 with the link
 * in out when it is http, https or mailto with no control characters; '"',
 * '`', '*' and '$', which the Shell acts on inside quotes, are
 * percent-encoded. 0 for any other link, or one too long for out: it is not
 * to be opened. */
int oam_link_for_browser(const char *link, char *out, size_t size);

#endif
