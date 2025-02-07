#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;
//inherit COMBINED;

mapping mpInfo = ([

"金精" : 	([ "prop" : ({1475,1079,1189,1004,0806,0906,1426}), "ski" : ({"高级防盾","高级强攻","高级复生","高级飞行术"})]),
"木精" : 	([ "prop" : ({1475,1079,1189,1004,0806,0906,1426}), "ski" : ({"高级防盾","高级狂攻","高级暴击","高级飞行术"})]),
"水精" : 	([ "prop" : ({1475,1079,1189,1004,0806,0906,1426}), "ski" : ({"高级法盾","福星高照","高级弱点攻击","高级飞行术"})]),
"火精" : 	([ "prop" : ({1330,0876,0991,1194,0970,1070,1240}), "ski" : ({"高级防盾","高级御法","火攻","灭天火法"})]),
"土精" : 	([ "prop" : ({1330,0876,0991,1194,0970,1070,1240}), "ski" : ({"高级御命术","高级御法","落石","飞沙走石"})]),
"龟仙人" : 	([ "prop" : ({1330,0876,0991,1194,0970,1070,1240}), "ski" : ({"高级复生","高级御法","水击","翻云覆雨"})]),

]);

mapping mpPet = (["石狮":0700,"石虎":0701,"刀俑":0850,"弓箭石俑":0853,"枪俑":0852,"剑俑":0851,]);

int get_item_value() {return 9975 ;}	//价格
int get_item_value_2() {return 9975 ;}	//会员价
int get_item_number() {return 97 ;}	//序号
//int get_item_color() {return 1 ;}
int give_pet(object who, string arg);


// 函数：构造处理
void create()
{
        set_name( "新年宠物包" );
        set_picid_1(3106);
        set_picid_2(3106);
        set_value(100);
        set_record(1);
	set_2( "use", ([
                "pet"          : (: give_pet :),
                	]) );
}

// 函数：获取描述
string get_desc() 
{ 
        return "装有极品宠物宝宝和丰富礼品的大礼包。";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me,this_object()); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me,object item )
{
	int id = getoid(item);
	send_user( me, "%c%c%w%s", ':',3,0,
		sprintf(
			"请选择你将要领取的宠物：\n"
			ESC"金精（技能：高级防盾、高级强攻、高级复生、高级飞行）\nuse %x# pet.1\n"
			ESC"木精（技能：高级防盾、高级狂攻、高级暴击、高级飞行）\nuse %x# pet.2\n"
			ESC"水精（技能：高级法盾、福星高照、高级弱点攻击、高级飞行）\nuse %x# pet.3\n"
			ESC"火精（技能：高级防盾、高级御法、火攻、灭天火法）\nuse %x# pet.4\n"
			ESC"土精（技能：高级御命术、高级御法、落石、飞沙走石）\nuse %x# pet.5\n"
			ESC"龟仙人（技能：高级复生、高级御法、水击、翻云覆雨）\nuse %x# pet.6\n"
			ESC"离开",id,id,id,id,id,id)
		
		);
	 
	return 0;	                        
} 

//物品给予玩家
int give_item(object who, string cName, int iAmount)
{
	int p;
	object item;
	
	item = new(cName);
	if ( !objectp(item) )
		return 0;
	if ( item->is_combined() )
		item->set_amount(iAmount>0?iAmount:1);
	p = item->move(who,-1);
	if ( !p )
	{
		destruct(item); 
		return 0;
	}
	item->add_to_user(p);
	return 1;	
}

int give_pet(object who, string arg)
{
	return __FILE__->give_pet_call(who,this_object(),arg);
}

int give_pet_call(object who, object item,string arg)
{
	int i=to_int(arg),picid,*nProp,size,iSki,p,j;
	string cName,*nSki,*nPet;
	object pet;
	mapping mpTmp;

	if ( who->get_beast_amount() + 1 > who->get_beast_max_amount() )
	{
		send_user(who, "%c%s", '!', "你的宠物空间已经满了，请放弃掉不要的宠物后再来使用宠物礼包吧。");
		return 1;
	}
	if ( USER_INVENTORY_D->count_empty_carry(who) < 14 )
	{
		send_user(who, "%c%s", '!', "你的背包空间不足15格，请清理一下你的道具空间后再使用新年宠物礼包吧。");
		return 1;
	}
	item->remove_from_user();
	destruct(item);

	switch(i)
	{
	default:
		cName = "金精";
		picid = 0950;
		break;
	case 2:
		cName = "木精";
		picid = 0951;
		break;	
	case 3:
		cName = "水精";
		picid = 0952;
		break;	
	case 4:
		cName = "火精";
		picid = 0953;
		break;	
	case 5:
		cName = "土精";
		picid = 0954;
		break;	
	case 6:
		cName = "龟仙人";
		picid = 0402;
		break;									
	}
	pet = USER_BEAST_D->give_pet(who,cName,1,0,picid,0);
	if ( !pet )
		return 1;
	pet->set_save("ignore_level",1);
	pet->init_skill_dbase();
	mpTmp = mpInfo[cName];
	nProp = mpTmp["prop"];
	nSki = mpTmp["ski"];
	pet->set_con_grow(nProp[0]);	
	pet->set_str_grow(nProp[1]);	
	pet->set_cps_grow(nProp[2]);	
	pet->set_mp_grow(nProp[3]);	
	pet->set_ma_grow(nProp[4]);	
	pet->set_md_grow(nProp[5]);	
	pet->set_dex_grow(nProp[6]);
	for(i=0,size=sizeof(nSki);i<size;i++)
	{
		iSki = "quest/pet"->get_beast_skill(nSki[i]);
		pet->set_skill(iSki,1);
	}
		
	NPC_PET_D->set_pet_info(pet);
	pet->set_life(8888);	
	pet->set_hp(pet->get_max_hp());
	pet->set_mp(pet->get_max_mp());
	pet->send_info();

	give_item(who,"/item/44/4404",2);	//玉灵液
	
	for(i=0;i<2;i++)		//精元丹
	{
		item = new("/item/44/4488");
		item->set("special",sprintf("%d","quest/pet"->get_drop_skill1()));
		p = item->move(who,-1);
		if(!p)
		{
			destruct(item);
			return 1;	
		}
		item->add_to_user(p);
	}	
	for(i=1;i<4;i++)		//晶石9颗 1,2,3级各3
	for(j=1;j<4;j++)
	{
		item = new(STONE_FILE->get_diamond_file());
		item->set_level(i);
		p = item->move(who,-1);
		if(!p)
		{
			destruct(item);
			return 1;	
		}
		item->add_to_user(p);
	}
	
	give_item(who,"/item/sell/0008",10);	//速效治愈药水
	give_item(who,"/item/sell/0010",10);	//速效恢复药水
	give_item(who,"/item/sell/0021",1);	//财神符
	
	return 1;
}
