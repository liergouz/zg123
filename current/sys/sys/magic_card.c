/***********
��������ģ��
*************/
#include <effect.h>
#include <skill.h>

// ���������ɶ�������
void SAVE_BINARY() { }

// ���������촦��
void create() 
{ 

}
//���������Ӱ��
void remove_effect(object who)
{
	int id;
	object obj;
	set_effect_2(who, EFFECT_MAGIC_CARD,0,0);
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 2, "" ); 
	id = who->get_2("magic_card.id");
	if ( id && (obj=load_object(sprintf("item/54/%04d.c",id))) )
		obj->remove_effect(who);	
	who->delete_2("magic_card");
	who->delete_save("magic_card");
}

int change_shape(object who,int iShape,int iTime )
{
	if ( get_effect(who, EFFECT_MAGIC_CARD) )
	{
		remove_effect(who);
	}
	set_effect_2(who, EFFECT_MAGIC_CARD, 1,iTime);
	who->set_save("magic_card", iShape);
	who->add_to_scene(get_z(who), get_x(who), get_y(who));  
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(who), 42431, 1, OVER_BODY, 42432, 1, OVER_BODY, PF_ONCE );
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"��Ϸ����" ); 
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 2, "����ʱ��" ); 
	who->set_2("magic_card.id",iShape);
	"/sys/sys/count"->add_task("����", 1);
	"/sys/sys/count"->add_task(sprintf("���� %04d",iShape), 1);
	return 1; 
}

void into_effect(object who)
{
	remove_effect(who);
	who->add_to_scene(get_z(who), get_x(who), get_y(who)); 
	send_user( get_scene_object_2(who, USER_TYPE), "%c%w%w%w%c%c%c", 0x4f, get_x(who), get_y(who), 9413, 1, OVER_BODY, PF_ONCE );    // ����ָ��
}

void effect_break(object who)
{
	remove_effect(who);   
}
//NPC����ָ�ԭ��
void into_npc_effect(object who)
{
	int picid,iShape;
	
	picid = who->get_save("primary_shape");
	if ( !picid )
		return ;
	who->delete_save("primary_shape");
	iShape = who->get_save("change_shape");
	who->delete_save("change_shape");
	who->set_char_picid(picid);
	if ( who->is_pet() )
	{
		if ( iShape == 501 )	//����
		{
			NPC_PET_D->count_max_hp(who);
			NPC_PET_D->count_max_mp(who);
			NPC_PET_D->count_ap(who);
			NPC_PET_D->count_dp(who);
			NPC_PET_D->count_cp(who);
			NPC_PET_D->count_pp(who);
			NPC_PET_D->count_sp(who);
		}
		who->send_info();
	}
	if ( !get_z(who) )
		return ;
	who->add_to_scene(get_z(who), get_x(who), get_y(who)); 
	send_user( get_scene_object_2(who, USER_TYPE), "%c%w%w%w%c%c%c", 0x4f, get_x(who), get_y(who), 9413, 1, OVER_BODY, PF_ONCE );    // ����ָ��
}
