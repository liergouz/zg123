
#include <equip.h>

string *buy_item = ({"��ľ��","��ì","ľ��","��ľ��","��������","��ʯ��","����","�鲼ñ","����Ь"});

string get_buy_name(object who)
{
	return buy_item[random(sizeof(buy_item))];	
}