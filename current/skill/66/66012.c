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
	set_number(12);
	set_name("青铜炸弹制作");
	set_skill_level(34);
	set_tool(500);
	set_tili(1);
	set_final("/item/final/16/1606");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(75);
        set_product( ([
	"255"	: 	4, 
	"1637"	: 	1, 
	"47"	: 	2, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0,       	     
        ])); 	
        set_count(5);
}
