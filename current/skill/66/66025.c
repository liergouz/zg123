#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(660);
	set_skill_type(1);
	set_number(25);
	set_name("银管制作");
	set_skill_level(48);
	set_tool(501);
	set_tili(0);
	set_final("/item/stuff/0281");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(95);
        set_product( ([
	"16"	: 	2, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}
