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
	set_number(301);
	set_name("����ǹ����");
	set_skill_level(35);
	set_tool(500);
	set_tili(1);
	set_final("/item/final/74/1035");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(1);
	set_base_rate(75);
        set_product( ([
	"251"	: 	2, 
	"249"	: 	2, 
	"101"	: 	2, 
	"311"	: 	1, 
//	��	: 	0, 
//	��	: 	0,            
        ])); 	
}
