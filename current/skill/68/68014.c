#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(680);
	set_skill_type(1);
	set_number(14);
	set_name("生地加工");
	set_skill_level(65);
	set_tool(0);
	set_tili(1);
	set_final("/item/stuff/0300");
	set_skill_temp(0);
	set_master("药店老板");
	set_skill_color(0);
	set_base_rate(100);
        set_product( ([
	"121"	: 	1, 
//		: 	0, 
//		: 	0, 
//		: 	0, 
//		: 	0, 
//		: 	0,            
        ])); 	
}
