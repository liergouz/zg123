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
	set_number(43);
	set_name("��ü������");
	set_skill_level(55);
	set_tool(501);
	set_tili(1);
	set_final("/item/final/75/1050");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(75);
        set_product( ([
	"23"	: 	3, 
	"252"	: 	3, 
	"240"	: 	2, 
	"32"	: 	1, 
//	��	: 	0, 
//	��	: 	0,            
        ])); 	
}
