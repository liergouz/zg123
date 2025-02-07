#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>

inherit OFFICER;
#define PET_NPC "npc/std/pet"

// 函数：获取人物造型
int get_char_picid() { return 6009; }
void do_welcome(string arg);
void do_reserve(string arg);
void do_release(string arg);

// 函数：构造处理
void create()
{
        set_name("宠物医生");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
                 "reserve"         : (: do_reserve :),
                 "release"         : (: do_release :),
        ]) );
        setup();
}

void do_look(object who)
{
	do_welcome("99");
	
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,id,i,size,iCash;
       	object who, *nPet,pet;
       	string cTmp,*nTmp;
       	
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);
        switch(flag)
        {
        case 1:
        	nPet = who->get_all_beast();
        	size = sizeof(nPet);
        	if ( !size )
        	{
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"宠物医生：\n    你的宠物呢？\n"ESC"离开",);
        		return ;	
        	}
        	for(i=0;i<size;i++)
        	{
        		pet = nPet[i];
        		iCash += pet->get_max_hp() - pet->get_hp() + pet->get_max_mp() - pet->get_mp();
        	}
        	if ( !iCash )
        	{
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"宠物医生：\n    你的宠物都很健康啊！\n"ESC"离开",);
        		return ;	
        	}
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("宠物医生：\n    你的宠物病得不轻啊～！看来确实需要得到治疗。放心啦～！我不会乱收钱的，我会根据你的宠物病的程度来收取费用，这次治疗需要花费%d金。\n"ESC"确定\ntalk %x# welcome.11\n"ESC"离开",iCash,id));
        	break;	
        case 2:
        	nPet = who->get_all_beast();
        	size = sizeof(nPet);
        	if ( !size )
        	{
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"宠物医生：\n    你的宠物呢？\n"ESC"离开",);
        		return ;	
        	}
        	for(i=0;i<size;i++)
        	{
        		pet = nPet[i];
        		iCash += (100-pet->get_faith())*45;
        	}
        	if ( !iCash )
        	{
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"宠物医生：\n    你的宠物都很忠心啊！\n"ESC"离开",);
        		return ;	
        	}
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("宠物医生：\n    你的宠物看起来似乎不听从你的召唤～！看来是你的宠物忠诚度低了。我能将你的宠物驯养的服服帖帖的，需要我的帮忙吗？这次驯养需要花费%d金。\n"ESC"确定\ntalk %x# welcome.21\n"ESC"离开",iCash,id));
        	break;	
        case 11:
        	nPet = who->get_all_beast();
        	size = sizeof(nPet);
        	if ( !size )	return;
        	for(i=0;i<size;i++)
        	{
        		pet = nPet[i];
        		iCash += pet->get_max_hp() - pet->get_hp() + pet->get_max_mp() - pet->get_mp();
        	}
        	if ( who->get_cash() < iCash )
        	{
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("宠物医生：\n    虽然不是给人治病，但也不能不收钱吧～！你还是想想办法再来吧～！\n"ESC"离开",));
        		return ;	
        	}
        	who->add_cash(-iCash);
        	for(i=0;i<size;i++)
        	{
        		pet = nPet[i];
        		pet->set_hp(pet->get_max_hp());
        		pet->set_mp(pet->get_max_mp());
        	}
        	break;
        case 21:
        	nPet = who->get_all_beast();
        	size = sizeof(nPet);
        	if ( !size )	return;
        	for(i=0;i<size;i++)
        	{
        		pet = nPet[i];
        		iCash += (100-pet->get_faith())*45;
        	}
        	if ( who->get_cash() < iCash )
        	{
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("宠物医生：\n    不要开玩笑了～！你怎么会没钱呢？没钱还能养的起宠物？呵呵～！把钱带够再来找我吧！\n"ESC"离开",));
        		return ;	
        	}
        	who->add_cash(-iCash);
        	for(i=0;i<size;i++)
        	{
        		pet = nPet[i];
        		pet->set_faith(100);
        	}
        	break;
        case 33:
        	if ( (size=sizeof(who->get_save_2("reserve_pet"))) >= 3 )
        	{
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"宠物医生：\n    寄存数量已达到上限！\n"ESC"离开",);
        		return ;
        	}
        	cTmp = sprintf("%s\n    可别小看本人，本人除了提供宠物医疗服务外，还特别提供宠物存取服务，请选择您要寄存的宠物：（%d/3）\n",me->get_name(),size);
		nPet = who->get_all_beast();
        	size = sizeof(nPet);
        	if ( !size )
        	{
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"宠物医生：\n    你好像还没有捕抓任何宠物哦。想抓一只宠物的话只要在杂货店购买"HIR"乾坤绳"NOR"后，对着怪物使用便可以了。\n"ESC"离开",);
        		return ;
        	}
        	for(i=0;i<size;i++)
        	{
        		if ( !objectp(pet=nPet[i]) )
        			continue;
        		cTmp += sprintf(ESC"%s%s %d级\ntalk %x# reserve.%x#\n",pet->get_blood()?HIG:"",pet->get_name(),pet->get_level(),id,getoid(pet));	
        	}
        	cTmp += ESC"离开";
        	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),cTmp);
        	break;
        case 44:
        	if ( (size=sizeof(who->get_save_2("reserve_pet"))) == 0 )
        	{
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"宠物医生：\n    你并没有在我这里寄存过宠物啊！\n"ESC"离开",);
        		return ;
        	}
        	nTmp = keys(who->get_save_2("reserve_pet"));
        	cTmp = sprintf("%s\n    请选择你所要取出的宠物：（%d/3）：\n",me->get_name(),size);
        	for(i=0;i<size;i++)
        	{
        		cTmp += sprintf(ESC"%s%s %d级\ntalk %x# release.%s\n",who->get_save_2(sprintf("reserve_pet.%s.baobao",nTmp[i]))?HIG:"",who->get_save_2(sprintf("reserve_pet.%s.name",nTmp[i])),who->get_save_2(sprintf("reserve_pet.%s.level",nTmp[i])),id,nTmp[i]);	
        		
        	}
        	cTmp += ESC"离开";
        	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),cTmp);
        	break;
        case 99:
        	
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("宠物医生：\n    你看清楚哦～！我可不是给人看病的医生，如果是你的宠物病了，或许我有些办法，来～先让我给你的宠物诊断诊断吧～！\n"ESC"宠物治疗\ntalk %x# welcome.1\n"ESC"宠物驯养\ntalk %x# welcome.2\n"ESC"存放宠物\ntalk %x# welcome.33\n"ESC"取出宠物\ntalk %x# welcome.44\n"ESC"离开",id,id,id,id));
        	break;	
        }

}
//寄存宠物
void do_reserve( string arg )
{
        object me = this_object();
        __FILE__ ->do_reserve2(me, arg);
}

void do_reserve2( object me, string arg )
{
	int size;
	string pet_id;
	object pet,who;
	
	who = this_player();
	
	pet = find_char(arg);
	if ( !pet )
		return ;
	if ( USER_BEAST_D->is_pet(who,pet) != 1 )
		return ;
	if ( (size=sizeof(who->get_save_2("reserve_pet"))) >= 3 )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"宠物医生：\n    寄存数量已达到上限！\n"ESC"离开",);
		return ;
	}
	pet_id = pet->get_pet_id();
	if ( !sizeof(pet_id) )
		return ;
	who->set_save_2(sprintf("reserve_pet.%s.name",pet_id),pet->get_name());
	who->set_save_2(sprintf("reserve_pet.%s.firstname",pet_id),pet->get_firstname());
	who->set_save_2(sprintf("reserve_pet.%s.level",pet_id),pet->get_level());
	who->set_save_2(sprintf("reserve_pet.%s.baobao",pet_id),pet->get_blood());
	pet->set("reserve_pet",1); //!!
	USER_BEAST_D->destruct_pet(who,pet);
	send_user(who,"%c%s",'!',"你寄存了一只宠物");

}
//取出寄存的宠物
void do_release( string arg )
{
        object me = this_object();
        __FILE__ ->do_release2(me, arg);
}

void do_release2( object me, string arg )
{
	mapping mpTmp;
	int size,j;
	object pet,who;
	
	who = this_player();	
	mpTmp = who->get_save_2(sprintf("reserve_pet.%s",arg));
	if ( !mpTmp )
		return ;
	if ( who->get_beast_amount() >= who->get_beast_max_amount() )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"宠物医生：\n    当前你所携带的宠物数量已达到上限！\n"ESC"离开",);
		return ;
	}

	pet = new(PET_NPC);
	if ( !pet )
		return;
	pet->set_owner(who);	//不设无法restore
	pet->set_pet_id(arg);
	j = pet->restore();
	if ( !j )
	{
		destruct(pet);
		return;	
	}
	pet->set_owner(who);	//必须
	pet->set_pet_id(arg);
	j = NPC_PET_D->set_pet_info(pet);
	if ( !j )
	{
		destruct(pet);
		return ;	
	}
	if ( !who->add_beast(pet) )
	{
		destruct(pet);
		return ;
	}
	pet->send_info();
	who->delete_save_2(sprintf("reserve_pet.%s",arg));
	send_user(who,"%c%s",'!',"你取回了一只宠物");
}