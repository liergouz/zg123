#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(620);
	set_skill_type(4);
	set_number(354);
	set_name("����������");
	set_skill_level(120);
	set_tool(502);
	set_tili(2);
	set_final("/item/final/76/1120");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(1);
	set_base_rate(75);
        set_product( ([
	"309"	: 	1, 
	"267"	: 	2, 
	"253"	: 	1, 
	"90"	: 	1, 
//	��	: 	0, 
//	��	: 	0,            
        ])); 	
}
