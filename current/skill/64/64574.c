#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(640);
	set_skill_type(1);
	set_number(574);
	set_name("流沙行装制作");
	set_skill_level(75);
	set_tool(511);
	set_tili(1);
	set_final("/item/final/60/4075");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(1);
	set_base_rate(75);
        set_product( ([
	"52"	: 	2, 
	"36"	: 	3, 
	"192"	: 	3, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}
