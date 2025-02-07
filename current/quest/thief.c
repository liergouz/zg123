
#include <equip.h>

string *buy_item = ({"¶ÌÄ¾µ¶","³¤Ã¬","Ä¾½£","³¤Ä¾¹÷","´ÖÂéÊÖÌ×","ËéÊ¯×Ó","ÂéÒÂ","Âé²¼Ã±","ÌÙÂûĞ¬"});

string get_buy_name(object who)
{
	return buy_item[random(sizeof(buy_item))];	
}