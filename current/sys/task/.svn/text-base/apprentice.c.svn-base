
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <npc.h>

mapping mpFamilyObj = ([
	"桃花源" : "/item/09/0901",
	"蜀山" : "/item/09/0902",
	"禁卫军" : "/item/09/0903",
	"唐门" : "/item/09/0904",
	"茅山" : "/item/09/0905",
	"昆仑山" : "/item/09/0906",
	"云梦泽" : "/item/09/0907",
	]);
mapping mpEquip = ([
	"桃花源" : ({"/item/70/0010",}),
	"蜀山" : ({"/item/73/0010","/item/72/0010"}),
	"禁卫军" : ({"/item/75/0010","/item/74/0010"}),
	"唐门" : ({"/item/71/1010",}),
	"茅山" : ({"/item/77/1010",}),
	"昆仑山" : ({"/item/78/1010",}),
	"云梦泽" : ({"/item/79/1010",}),
	]);
void do_give_familyobj(object player,object master);
int challenge(object player,object master);

int * spec_skill = ({ 0211, 0212, 0316, 0317, 0319, 0221, 0231, 0222, 0325, 0329, 0241, 0251, 0242, 0348, 0349, 0261, 0363, 0364, 0365, 0368, 0271, 0413, 0414, 0417, 0418, 0421, 0422, 0423, 0424, 0425, 0281, 0501, 0511, 0531, 0591, });
			
// 函数：生成二进制码
void SAVE_BINARY() { }

void do_look(object player, object master )
{
        string name1, name2, result = "", word;
        int order1, order2;
        name1 = player->get_fam_name();
        name2 = master->get_fam_name();	
        order1 = player->get_fam_order();
        order2 = master->get_fam_order();
        if (master->get_fam_order()>4 && name1==name2)
                result = sprintf("%s：\n你可以在师傅那里学到本门的绝技。还有，师傅会安排各种各样的任务要求你去完成。\n", master->get_name());
        else
        {                
                word = "/quest/master"->get_answer(name2, master->get_fam_order()) ;      
                result = sprintf("%s：\n%s\n", master->get_name(), word);          
        }
        if (name1==name2&& order2==4)
        	result += sprintf(ESC"购买本门派装备\nlist %x#\n",getoid(master));
        if (name1==""&& order2==4 || name1==name2 && (order1==order2||order1==0) )        
                result += sprintf(ESC"哪里可以买到本门派的武器？\ntalk %x# apprentice.11\n"ESC"拜师\ntalk %x# apprentice.12\n"ESC"只是来拜访一下而已\nCLOSE\n", getoid(master), getoid(master));
        else if ( name1 == name2 && order2 == 7 && !player->get_save_2("init_gift7"))
        	result += sprintf("为使本门派弟子能更好的发挥本门派武学精髓，本长老特提供免费洗点一次。\n"ESC"免费洗点\ntalk %x# init.1\n",getoid(master));
	result += ESC"离开\nCLOSE";        	
        send_user( player, "%c%s", ':', result );                                                
}

string get_chat(object player, object master )
{
        string name1, name2, result = "", word;
        int order1, order2;
        name1 = player->get_fam_name();
        name2 = master->get_fam_name();	
        order1 = player->get_fam_order();
        order2 = master->get_fam_order();
        if (master->get_fam_order()>4 && name1==name2)
                result = sprintf("%s：\n你可以在师傅那里学到本门的绝技。还有，师傅会安排各种各样的任务要求你去完成。\n", master->get_name());
        else
        {                
                result = "/quest/master"->get_answer(name2, master->get_fam_order()) ;      
        }
	return result;
}
void do_apprentice(object player, object master, string arg )
{
        string name1, name2, result = "";
        int order1, order2, flag, i, size ;
        object *nEquip,item;
	string *nTmp,tmp;
	
        name1 = player->get_fam_name();
        name2 = master->get_fam_name();	
        order1 = player->get_fam_order();
        order2 = master->get_fam_order();
        flag = to_int(arg);
	switch(flag)
        {
        case 11:       
        	if ( name2 == "禁卫军" )
        		result = master->get_name()+"：\n    在周国的武器店（215，202）和防具店（177，181）就能买到本门派的装备武器。";
        	else if ( name2 == "桃花源" )
        		result = master->get_name()+"：\n    在赵国的武器店（172，060）和防具店（184，088）就能买到本门派的装备武器。";
        	else if ( name2 == "蜀山" )
        		result = master->get_name()+"：\n    在燕国的武器店（237，242）和防具店（220，230）就能买到本门派的装备武器。";
        	else if ( name2 == "唐门" )
        		result = master->get_name()+"：\n    在韩国的武器店（213，106）和防具店（197，97）就能买到本门派的装备武器。另外你必须注意，使用暗器攻击敌人，必须先学会本门的武功“漫天花雨”。";
        	else if ( name2 == "昆仑山" )
        		result = master->get_name()+"：\n    在秦国的武器店（137，158）和防具店（125，149）就能买到本门派的装备武器。";
        	else if ( name2 == "茅山" )
        		result = master->get_name()+"：\n    在齐国的武器店（139，162）和防具店（135，154）就能买到本门派的装备武器。";
        	else if ( name2 == "云梦泽" )
        		result = master->get_name()+"：\n    在魏国的武器店（291，154）和防具店（279，165）就能买到本门派的装备武器。";
		else
			return;
		send_user(player,"%c%c%w%s",':',3,master->get_char_picid(),result);
        	return;
        case 12:
		send_user(player,"%c%c%w%s",':',3,master->get_char_picid(),sprintf("%s：\n    加入本门你就得进行艰苦的磨炼与修行，你真的确定要拜我为师吗？\n"ESC"确定\ntalk %x# apprentice\n"ESC"我还是再考虑考虑……",master->get_name(),getoid(master)));
		return ;
        case 13:
		send_user(player,"%c%c%w%s",':',3,master->get_char_picid(),sprintf("%s：\n    徒儿你真的要放弃为师交付予你的任务吗？如果你真的确定如此，那么在三分钟内为师是不会再给予你新的任务。\n"ESC"接受任务\ntalk %x# accept_quest\n"ESC"拒绝任务\ntalk %x# apprentice.14\n",master->get_name(),getoid(master), getoid(master)));
		return ;
	case 14:
		item = player->get_equip(HAND_TYPE);
		if (item && item->get_item_number()==10001078)
		{
                        send_user( player, "%c%c%s", 0x59, 1, sprintf("你是否使用'瞒天过海符'来消除你的任务间隔时间？\n"
                        	ESC "%c\n"ESC"use %x# master2\n"
                                , 1, getoid(item) ) );				
		}
		return;
        case 15:
        	//检查能否学习强化技能。
		TASK_MASTER_D->check_enhance_sk( player, master);
		return;

        } 
        // 拜师
        if  ( (name1==""&& order2==4 || name1==name2 && (order1==order2||order1==0) ) && player->get_fam_master()!= master->get_name() )
        {        	
                if (player->get_level()<10)
                {
                        result = sprintf("%s：\n    你还没有到十级呢，我无法收你。\n", master->get_name());         
                        send_user( player, "%c%s", ':', result );             
                        return;                
                }     
                nEquip = player->get_all_equip();            
                if (nEquip[WEAPON_POSITION]!=0)
                {
                        result = sprintf("%s：\n    请取下武器再来找我。\n", master->get_name());         
                        send_user( player, "%c%s", ':', result );             
                        return;                
                }         
                if ( USER_INVENTORY_D->get_free_count(player) < 1 )
                {
                        result = sprintf("%s：\n    你身上的道具栏已满，请清空一下再来拜师。\n", master->get_name());         
                        send_user( player, "%c%s", ':', result );             
                        return;                
                }      
		nTmp = mpEquip[name2];
		if ( sizeof(nTmp) == 0 )
			return ;
		tmp = nTmp[random(sizeof(nTmp))];
		item = new(tmp);
		if ( !item )
			return ;
		i = item->move2(player);
		item->add_to_user(i);
		send_user(player,"%c%s",';',sprintf("你获得了师傅赠送的门派武器"HIR"%s",item->get_name()));               
                if (name1=="") 
                {
                        player->set_fam_name(name2);
                        "/sys/sys/count"->add_family(name2, 1);                    
                        for (i=(player->get_fam_type()-1)*5;i<player->get_fam_type()*5;i++)
                        {
                        	if (player->get_skill(spec_skill[i])<=0)
                        		player->set_skill(spec_skill[i], 1);
                        }
                }
		player->use_equip(item);
                player->set_save("famrec", 1);
                if (order1!=order2)  player->set_fam_order(order2);
                player->set_fam_master(master->get_name());
                player->set_fam_time( time() );
                FAMILY_D->family_channel( name2, 0, sprintf( HIY "%s(%d)决定投入%s的%s门下。", player->get_name(), player->get_number(), name2, master->get_name() ) );                        
		if ( player->get_legend(TASK_49, 11) && !player->get_legend(TASK_49, 12) )
			USER_TASK_D->send_task_intro(player,2,TID_NEWBIE_01,118);	
                result = sprintf("你拜入%s的%s门下！", name2, master->get_name());
                send_user( player, "%c%s", '!', result );
                result = sprintf("%s：\n那我就收下你吧。\n", master->get_name());         
                send_user( player, "%c%s", ':', result );           
                USER_ENERGY_D->count_max_yuan(player);                
                if ( !nEquip[FAMILY_POSITION] )         
                {
                	do_give_familyobj(player,master);
                }
                else if ( nEquip[FAMILY_POSITION]->is_newplayer() == 1 )	//新手信物
                {
                	nEquip[FAMILY_POSITION]->remove_from_user();
                	destruct(nEquip[FAMILY_POSITION]);
                	player->set_equip( FAMILY_TYPE, 0 );
                	do_give_familyobj(player,master);
                }
                send_user( get_scene_object_2(player, USER_TYPE), "%c%d%d%w", 0x23, getoid(player), 
                                	player->get_armor_code(), player->get_armor_color_1() ); 
        }                
        switch(flag)
        {
        case 1:
                if (player->get_fam_master()== master->get_name() && order1!=order2 )
                {
                        result = sprintf("%s：\n你已经尽得我的真传，可以找更高级的师父拜师了。\n", master->get_name()); 
                        send_user( player, "%c%s", ':', result );   
                        return;                        
                }                             
                if ( order2 == 1 )
                	return ;
                if (time() - player->get_save_2("masterfight.time")<3600)
                {
                        result = sprintf("%s：\n哼，这么快就想再次挑战？为师觉得你还需要努力提高才行。\n", master->get_name()); 
                        send_user( player, "%c%s", ':', result );   
                        return;
                }
                if (player->get_level() < master->get_level() -15 )
                {
                        result = sprintf("%s：\n徒儿也未免太过于急进了，以你现在的能力还远远不足以接受师门的挑战。你还是到了%d级之后再来吧。\n", master->get_name(),master->get_level() -15); 
                        send_user( player, "%c%s", ':', result );   
                        return;
                }
                else if (player->get_level() < master->get_level() -5 )
                {
                        result = sprintf("%s：\n以徒儿现在的能力进行这个挑战还是有一定的难度，如果不作好充分准备的话吃亏的可是自己啊。你确定现在就要进入练武场挑战吗？\n"ESC"我要挑战\ntalk %x# apprentice.2\n"ESC"我还是考虑一下", master->get_name(),getoid(master)); 
                        send_user( player, "%c%s", ':', result );   
                        return;
                }
                else
                {
                        result = sprintf("%s：\n好！今天就让我看看徒儿的能力如何。只要你成功闯过这一关，便可百尺竿头，更上一层楼！\n"ESC"我要挑战\ntalk %x# apprentice.2\n"ESC"我还是考虑一下", master->get_name(),getoid(master)); 
                        send_user( player, "%c%s", ':', result );   
                        return;
                }
                break;                
        case 2:
                if (player->get_fam_master()== master->get_name() && order1!=order2 )
                {
                        result = sprintf("%s：\n你已经尽得我的真传，可以找更高级的师父拜师了。\n", master->get_name()); 
                        send_user( player, "%c%s", ':', result );   
                        return;                        
                }                             
                if ( order2 == 1 )
                	return ;
                if (time() - player->get_save_2("masterfight.time")<3600)
                {
                        result = sprintf("%s：\n哼，这么快就想再次挑战？为师觉得你还需要努力提高才行。\n", master->get_name()); 
                        send_user( player, "%c%s", ':', result );   
                        return;
                }
                if (player->get_level() < master->get_level() -15 )
                {
                        result = sprintf("%s：\n徒儿要加把劲才好，目前你的能力不行。\n", master->get_name()); 
                        send_user( player, "%c%s", ':', result );   
                        return;
                }
		challenge(player,master);
                break;                
        }
}

void do_give_familyobj(object player,object master)
{
	string name2,cFile;
	object item;

	name2 = master->get_fam_name();	
        cFile = mpFamilyObj[name2];
        if ( !stringp(cFile) )
        	return;                
	item = new(cFile);
	if ( !item )
		return ;
	item->set_item_level(1);
	item->init_familyobj();
	if ( !player->restore_equip(item) )
	{
		destruct(item);
		return ;
	}
	USER_ENERGY_D->count_all_prop(player);
	player->init_beast();
	tell_user(player,"你得到了师门信物: "HIY+cFile->get_name());
	"skill/00/00051"->can_perform(player);
}
//师门挑战
int challenge(object player,object master)
{
	int x,y,z,level,p,d,family,ord;
	string cityname;
	object map,npc;
	
	ord = master->get_fam_order();
	if ( ord == 4 )
		level = 60;
	else if ( ord == 3 )
		level = 90;
	else if ( ord == 2 )
		level = 120;
	else if ( ord == 1 )
		level = 150;
	else
		return 0;
	if( ( z = find_map_flag(1000, 2999, 0) ) <= 0 ) return 1;
	x = ( p % 1000000 ) / 1000;  y = p % 1000;
	npc = new( "npc/90/app_fight" );
	if (!npc) return 0;
	npc->set("level", level);
	switch(master->get_fam_name())
	{
	case "桃花源": 	
	        family = 10; 
	        d = 891;
	        cityname = "桃花岛";
	        break;
	case "蜀山": 	
	        family = 20; 
	        d = 892;
	        cityname = "蜀岭峰";			        
	        break;
	case "禁卫军": 	
	        family = 30; 
	        d = 893;
	        cityname = "禁卫军营地";			        				        
	        break;
	case "唐门": 	
	        family = 40; 
	        d = 894;
	        cityname = "唐门密室";			        
	        break;
	case "茅山": 	
	        family = 50; 
	        d = 895;
	        cityname = "鬼门府";			        
	        break;
	case "昆仑山": 	
	        family = 60; 
	        d = 896;
	        cityname = "昆仑仙境";			        
	        break;
	default: 	
	        family = 70; 
	        d = 897;
	        cityname = "死亡沼泽";			        
	        break;
	}
        init_virtual_map(z, d);		
        map = new( NEWBIE );
        map->set_client_id(d);
        map->set_owner(player);
        set_map_object( map, map->set_id(z) );       
        map->set_name(cityname);    
        p = get_jumpin(z, 1);
	NPC_ENERGY_2_D->init_family(npc, family, level, -1);
	npc->set_fam_name(master->get_fam_name());
	npc->set_char_type(FIGHTER_TYPE_2);
	npc->set_name(cityname+"守卫");
	npc->set_level(level);
	NPC_ENERGY_D->init_family1(npc);
	x = p/1000, y = p % 1000;
	npc->set("f_z",z);
	npc->set("f_x",x);
	npc->set("f_y",y);
	npc->set("user", player->get_number());
	npc->set("fight", player);
        player->set_2("masterfight.x", get_x(player));
	player->set_2("masterfight.y", get_y(player));
	player->set_2("masterfight.z", get_z(player));   		
	if( p = get_valid_xy(z, x, y, IS_CHAR_BLOCK) )
        {
                x = p/1000, y = p % 1000;
                player->add_to_scene(z, x, y, 3);
             
        }	
        player->set_save_2("masterfight.time",time());
        player->set_save_2("masterfight.status", 1);
        npc->do_fight(16);			        
	return 1;	
}