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
	set_number(37);
	set_name("机械小猴制作");
	set_skill_level(61);
	set_tool(501);
	set_tili(1);
	set_final("/item/final/16/1624");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(75);
        set_product( ([
	"266"	: 	4, 
	"1610"	: 	1, 
	"1628"	: 	1, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}
