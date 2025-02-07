#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>

inherit OFFICER;
#define PET_NPC "npc/std/pet"

// ��������ȡ��������
int get_char_picid() { return 6009; }
void do_welcome(string arg);
void do_reserve(string arg);
void do_release(string arg);

// ���������촦��
void create()
{
        set_name("����ҽ��");
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
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"����ҽ����\n    ��ĳ����أ�\n"ESC"�뿪",);
        		return ;	
        	}
        	for(i=0;i<size;i++)
        	{
        		pet = nPet[i];
        		iCash += pet->get_max_hp() - pet->get_hp() + pet->get_max_mp() - pet->get_mp();
        	}
        	if ( !iCash )
        	{
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"����ҽ����\n    ��ĳ��ﶼ�ܽ�������\n"ESC"�뿪",);
        		return ;	
        	}
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("����ҽ����\n    ��ĳ��ﲡ�ò��ᰡ��������ȷʵ��Ҫ�õ����ơ������������Ҳ�������Ǯ�ģ��һ������ĳ��ﲡ�ĳ̶�����ȡ���ã����������Ҫ����%d��\n"ESC"ȷ��\ntalk %x# welcome.11\n"ESC"�뿪",iCash,id));
        	break;	
        case 2:
        	nPet = who->get_all_beast();
        	size = sizeof(nPet);
        	if ( !size )
        	{
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"����ҽ����\n    ��ĳ����أ�\n"ESC"�뿪",);
        		return ;	
        	}
        	for(i=0;i<size;i++)
        	{
        		pet = nPet[i];
        		iCash += (100-pet->get_faith())*45;
        	}
        	if ( !iCash )
        	{
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"����ҽ����\n    ��ĳ��ﶼ�����İ���\n"ESC"�뿪",);
        		return ;	
        	}
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("����ҽ����\n    ��ĳ��￴�����ƺ�����������ٻ�������������ĳ����ҳ϶ȵ��ˡ����ܽ���ĳ���ѱ���ķ��������ģ���Ҫ�ҵİ�æ�����ѱ����Ҫ����%d��\n"ESC"ȷ��\ntalk %x# welcome.21\n"ESC"�뿪",iCash,id));
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
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("����ҽ����\n    ��Ȼ���Ǹ����β�����Ҳ���ܲ���Ǯ�ɡ����㻹������취�����ɡ���\n"ESC"�뿪",));
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
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("����ҽ����\n    ��Ҫ����Ц�ˡ�������ô��ûǮ�أ�ûǮ�������������Ǻǡ�����Ǯ�����������Ұɣ�\n"ESC"�뿪",));
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
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"����ҽ����\n    �Ĵ������Ѵﵽ���ޣ�\n"ESC"�뿪",);
        		return ;
        	}
        	cTmp = sprintf("%s\n    �ɱ�С�����ˣ����˳����ṩ����ҽ�Ʒ����⣬���ر��ṩ�����ȡ������ѡ����Ҫ�Ĵ�ĳ����%d/3��\n",me->get_name(),size);
		nPet = who->get_all_beast();
        	size = sizeof(nPet);
        	if ( !size )
        	{
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"����ҽ����\n    �����û�в�ץ�κγ���Ŷ����ץһֻ����Ļ�ֻҪ���ӻ��깺��"HIR"Ǭ����"NOR"�󣬶��Ź���ʹ�ñ�����ˡ�\n"ESC"�뿪",);
        		return ;
        	}
        	for(i=0;i<size;i++)
        	{
        		if ( !objectp(pet=nPet[i]) )
        			continue;
        		cTmp += sprintf(ESC"%s%s %d��\ntalk %x# reserve.%x#\n",pet->get_blood()?HIG:"",pet->get_name(),pet->get_level(),id,getoid(pet));	
        	}
        	cTmp += ESC"�뿪";
        	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),cTmp);
        	break;
        case 44:
        	if ( (size=sizeof(who->get_save_2("reserve_pet"))) == 0 )
        	{
        		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"����ҽ����\n    �㲢û����������Ĵ�����ﰡ��\n"ESC"�뿪",);
        		return ;
        	}
        	nTmp = keys(who->get_save_2("reserve_pet"));
        	cTmp = sprintf("%s\n    ��ѡ������Ҫȡ���ĳ����%d/3����\n",me->get_name(),size);
        	for(i=0;i<size;i++)
        	{
        		cTmp += sprintf(ESC"%s%s %d��\ntalk %x# release.%s\n",who->get_save_2(sprintf("reserve_pet.%s.baobao",nTmp[i]))?HIG:"",who->get_save_2(sprintf("reserve_pet.%s.name",nTmp[i])),who->get_save_2(sprintf("reserve_pet.%s.level",nTmp[i])),id,nTmp[i]);	
        		
        	}
        	cTmp += ESC"�뿪";
        	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),cTmp);
        	break;
        case 99:
        	
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("����ҽ����\n    �㿴���Ŷ�����ҿɲ��Ǹ��˿�����ҽ�����������ĳ��ﲡ�ˣ���������Щ�취�����������Ҹ���ĳ��������ϰɡ���\n"ESC"��������\ntalk %x# welcome.1\n"ESC"����ѱ��\ntalk %x# welcome.2\n"ESC"��ų���\ntalk %x# welcome.33\n"ESC"ȡ������\ntalk %x# welcome.44\n"ESC"�뿪",id,id,id,id));
        	break;	
        }

}
//�Ĵ����
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
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"����ҽ����\n    �Ĵ������Ѵﵽ���ޣ�\n"ESC"�뿪",);
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
	send_user(who,"%c%s",'!',"��Ĵ���һֻ����");

}
//ȡ���Ĵ�ĳ���
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
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"����ҽ����\n    ��ǰ����Я���ĳ��������Ѵﵽ���ޣ�\n"ESC"�뿪",);
		return ;
	}

	pet = new(PET_NPC);
	if ( !pet )
		return;
	pet->set_owner(who);	//�����޷�restore
	pet->set_pet_id(arg);
	j = pet->restore();
	if ( !j )
	{
		destruct(pet);
		return;	
	}
	pet->set_owner(who);	//����
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
	send_user(who,"%c%s",'!',"��ȡ����һֻ����");
}