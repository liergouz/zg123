#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(620);
	set_skill_type(3);
	set_number(74);
	set_name("ף�ڻ�ǹ����");
	set_skill_level(85);
	set_tool(501);
	set_tili(1);
	set_final("/item/final/74/1080");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(75);
        set_product( ([
	"266"	: 	3, 
	"264"	: 	3, 
	"283"	: 	1, 
	"36"	: 	3, 
	"218"	: 	1, 
//	��	: 	0,            
        ])); 	
}
