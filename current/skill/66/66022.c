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
	set_number(22);
	set_name("铁制轴承制作");
	set_skill_level(45);
	set_tool(501);
	set_tili(0);
	set_final("/item/final/16/1608");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(75);
        set_product( ([
	"260"	: 	2, 
	"255"	: 	2, 
	"261"	: 	2, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}
