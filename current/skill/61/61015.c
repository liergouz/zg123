#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(610);
	set_skill_type(1);
	set_number(15);
	set_name("�ſ������");
	set_skill_level(75);
	set_tool(0);
	set_tili(1);
	set_final("/item/final/33/1761");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(95);
        set_product( ([
	"146"	: 	3, 
	"221"	: 	2, 
//	��	: 	0, 
//	��	: 	0, 
//	��	: 	0, 
//	��	: 	0,       	     
        ])); 	
        set_count(1);
}
