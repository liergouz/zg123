#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(640);
	set_skill_type(6);
	set_number(163);
	set_name("锦线制作");
	set_skill_level(90);
	set_tool(512);
	set_tili(0);
	set_final("/item/stuff/0241");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(95);
        set_product( ([
	"53"	: 	1, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}
