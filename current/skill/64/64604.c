#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(640);
	set_skill_type(2);
	set_number(604);
	set_name("波形头巾制作");
	set_skill_level(85);
	set_tool(511);
	set_tili(1);
	set_final("/item/final/65/2085");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(1);
	set_base_rate(75);
        set_product( ([
	"52"	: 	5, 
	"191"	: 	2, 
	"85"	: 	1, 
	"218"	: 	1, 
//	无	: 	0, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}
