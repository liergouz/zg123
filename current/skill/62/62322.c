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
	set_number(322);
	set_name("���Ǵ̶���");
	set_skill_level(65);
	set_tool(501);
	set_tili(1);
	set_final("/item/final/71/1065");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(1);
	set_base_rate(75);
        set_product( ([
	"38"	: 	3, 
	"258"	: 	3, 
	"1820"	: 	2, 
	"312"	: 	1, 
//	��	: 	0, 
//	��	: 	0,            
        ])); 	
}
