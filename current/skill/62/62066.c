#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(620);
	set_skill_type(1);
	set_number(66);
	set_name("ӥצȭ�׶���");
	set_skill_level(76);
	set_tool(501);
	set_tili(1);
	set_final("/item/final/70/1070");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(75);
        set_product( ([
	"257"	: 	3, 
	"37"	: 	3, 
	"36"	: 	2, 
	"218"	: 	1, 
//	��	: 	0,            
//	��	: 	0,  
        ])); 	
}
