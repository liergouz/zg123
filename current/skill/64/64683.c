#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(640);
	set_skill_type(2);
	set_number(683);
	set_name("�ǳ�ս������");
	set_skill_level(120);
	set_tool(512);
	set_tili(2);
	set_final("/item/final/65/1120");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(1);
	set_base_rate(75);
        set_product( ([
	"54"	: 	4, 
	"274"	: 	3, 
	"27"	: 	3, 
	"218"	: 	3, 
	"320"	: 	1, 
//	��	: 	0,       	     
        ])); 	
        set_count(1);
}
