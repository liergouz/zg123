#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(620);
	set_skill_type(5);
	set_number(327);
	set_name("����������");
	set_skill_level(75);
	set_tool(501);
	set_tili(1);
	set_final("/item/final/75/1075");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(1);
	set_base_rate(75);
        set_product( ([
	"22"	: 	3, 
	"311"	: 	1, 
	"62"	: 	1, 
	"310"	: 	1, 
//	��	: 	0, 
//	��	: 	0,            
        ])); 	
}
