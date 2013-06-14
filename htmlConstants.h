#ifndef HTMLCONSTANTS_H
#define HTMLCONSTANTS_H

#include <QString>

QString STYLE = QString("<style type=\"text/css\">\n"
		"div.numpage {\n\tpage-break-after: always;\n"
        "\tfont-family: Verdana, Geneva, sans-serif;\n"
		"\tfont-size:11px;\n\tfont-color:#333333;\n\tpadding: 2px;\n}"
        "\ntable.gridtable {\n\tfont-family: Verdana, Geneva, sans-serif;\n"
		"\tfont-size:14px;\n\tcolor:#333333;\n\tborder-width: 1px;\n"
		"\tborder-color: #666666;\n\tborder-collapse: collapse;\n}\n"
        "table.gridtable th {\n\tfont-family: Verdana, Geneva, sans-serif;\n"
		"\tfont-size:20px;\n\tborder-width: 2px;\n\tpadding: 4px;\n"
		"\tborder-style: solid;\n\tborder-color: #666666;\n"
		"\tbackground-color: #dedede;\n}\n"
		"table.gridtable td {\n\tborder-width: 2px;\n\tpadding: 4px;\n"
		"\tborder-style: solid;\n\tborder-color: #666666;\n"
		"\tbackground-color: #ffffff;\n}\n</style>\n\n");

QString PAGE_NUM("<div class=\"numpage\" align=\"center\">- P&aacute;g %1 -</div>");

QString TABLE_INIT = QString("<table width=100% class=\"gridtable\">\n"
	"<tr><th width=50%>ALUMNA</th><th  width=10%>CUMPLEA&Ntilde;OS</th>"
	"<th width=40%>TEL&Eacute;FONOS</th></tr>");

QString ROW("<tr><td valign=\"top\"><b>%1</b></br>%2</td>"
			"<td align=\"center\" valign=\"top\">%3</td>"
			"<td align=\"right\" valign=\"top\">%4</td></tr>\n");

QString END_TABLE = QString("</table>") + PAGE_NUM;

QString HTML_INIT = STYLE + QString("<html>\n<head>"
	"<meta content=\"text/html;\" http-equiv=\"content-type\" "
	"charset=\"utf-8\"></head>\n<body>") + TABLE_INIT;

QString END_HTML = END_TABLE + QString("</body></html>");

#endif // HTMLCONSTANTS_H
