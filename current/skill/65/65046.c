#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(650);
	set_skill_type(1);
	set_number(46);
	set_name("高级血气制作");
	set_skill_level(49);
	set_tool(516);
	set_tili(1);
	set_final("/item/final/15/1512");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(75);
        set_product( ([
	"83"	: 	1, 
	"82"	: 	1, 
	"58"	: 	1, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}
