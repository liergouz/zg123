#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(640);
	set_skill_type(3);
	set_number(587);
	set_name("Զ��Ь����");
	set_skill_level(75);
	set_tool(511);
	set_tili(1);
	set_final("/item/final/88/6075");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(1);
	set_base_rate(75);
        set_product( ([
	"52"	: 	4, 
	"283"	: 	3, 
	"103"	: 	1, 
	"310"	: 	1, 
//	��	: 	0, 
//	��	: 	0,       	     
        ])); 	
        set_count(1);
}
