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
	set_number(630);
	set_name("御风鞋制作");
	set_skill_level(95);
	set_tool(512);
	set_tili(1);
	set_final("/item/final/88/2095");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(1);
	set_base_rate(75);
        set_product( ([
	"54"	: 	5, 
	"263"	: 	2, 
	"86"	: 	1, 
	"309"	: 	1, 
//	无	: 	0, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}
