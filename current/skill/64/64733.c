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
	set_number(733);
	set_name("风神履制作");
	set_skill_level(67);
	set_tool(511);
	set_tili(4);
	set_final("/item/final/88/8066");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(2);
	set_base_rate(65);
        set_product( ([
	"50"	: 	4, 
	"259"	: 	4, 
	"32"	: 	3, 
//	无	: 	0, 
	"323"	: 	3, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}
