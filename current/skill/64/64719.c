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
	set_number(719);
	set_name("追风法袍制作");
	set_skill_level(47);
	set_tool(511);
	set_tili(4);
	set_final("/item/final/60/8046");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(2);
	set_base_rate(65);
        set_product( ([
	"48"	: 	5, 
	"322"	: 	5, 
	"215"	: 	2, 
	"312"	: 	2, 
	"323"	: 	3, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}
