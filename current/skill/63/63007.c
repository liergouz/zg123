#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(630);
	set_skill_type(1);
	set_number(7);
	set_name("玉容膏炼制");
	set_skill_level(21);
	set_tool(505);
	set_tili(1);
	set_final("/item/final/91/1800");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(75);
        set_product( ([
	"288"	: 	2, 
	"289"	: 	2, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}
