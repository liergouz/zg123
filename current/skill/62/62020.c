#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(620);
	set_skill_type(2);
	set_number(20);
	set_name("�󿳵�����");
	set_skill_level(33);
	set_tool(500);
	set_tili(1);
	set_final("/item/final/72/1030");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(75);
        set_product( ([
	"249"	: 	2, 
	"248"	: 	2, 
	"35"	: 	1, 
	"32"	: 	1, 
//	��	: 	0, 
//	��	: 	0,            
        ])); 	
}
