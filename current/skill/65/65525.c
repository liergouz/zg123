#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(650);
	set_skill_type(2);
	set_number(525);
	set_name("琥珀项链制作");
	set_skill_level(55);
	set_tool(516);
	set_tili(1);
	set_final("/item/final/86/2055");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(1);
	set_base_rate(75);
        set_product( ([
	"60"	: 	1, 
	"50"	: 	2, 
	"78"	: 	1, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}
