#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(620);
	set_skill_type(6);
	set_number(316);
	set_name("风魔袖里箭锻造");
	set_skill_level(55);
	set_tool(501);
	set_tili(1);
	set_final("/item/final/71/1055");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(1);
	set_base_rate(75);
        set_product( ([
	"39"	: 	3, 
	"253"	: 	3, 
	"1820"	: 	1, 
	"312"	: 	1, 
//	无	: 	0, 
//	无	: 	0,            
        ])); 	
}
