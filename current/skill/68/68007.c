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
	set_number(7);
	set_name("何首乌加工");
	set_skill_level(40);
	set_tool(0);
	set_tili(1);
	set_final("/item/stuff/0293");
	set_skill_temp(0);
	set_master("药店老板");
	set_skill_color(0);
	set_base_rate(100);
        set_product( ([
	"113"	: 	1, 
//		: 	0, 
//		: 	0, 
//		: 	0, 
//		: 	0, 
//		: 	0,            
        ])); 	
}
