
// �Զ����ɣ�/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
private int iAtt,iCast;

int set_attack(int i)
{
	return iAtt = i;
}
int set_caster(int i)
{
	return iCast = i;
}

// ������Զ�̹����Ĺ�
int is_caster() { return iCast; }
//������
int is_copy_npc() { return 1; }

// ������Զ�̹����Ĺ�
// int is_caster() { return 1; }

// �������Ƿ������ƶ�
// int is_moveable() { return 0; }    // ��ֹʹ�� go ����

// �������������(����֮�е���)
// void follow_user() { }    // ��ֹ�������


// ���������촦��
void create()
{
        set_name("�þ���");

//        set_char_type(FIGHTER_TYPE);    // init_level Ҫ�õ�
//        
//        set_head_color(0x0);
//
//        NPC_ENERGY_D->init_level( this_object(), 1+ random(2) );    // 
//        set_max_seek(4);

        setup();
	set("anti_05311",1);	//�����Ի�
//        set_char_type(FIGHTER_TYPE);    // ��������
}

//// ��������ȡװ������
//int get_weapon_code() { return UNARMED; }
//
//// �������ؼ���������
//int perform_action( object who ) { return 0; }    // XXXXX->perform_action_npc( this_object(), who ); }

// ��������������
void drop_items( object who ) 
{
	"sys/copy/mirror"->npc_die( this_object(), who ); 
}
//�ӳ�X�����
void delay_appear(int z,int x ,int y,int sec)
{
	call_out("add_to_scene",sec,z,x,y);
}


// �������ؼ���������
int perform_action( object who ) 
{ 
	if ( iAtt == 1 )
		return PF_FILE_04232->perform_action_npc( this_object(), who ); //����
	else if ( iAtt == 2)
		return PF_FILE_01611->perform_action_npc( this_object(), who ); //����
}

// ������������������,�ڸ����ڵĶ�����
object *correct_bonus_team( object *team )
{
        object *team2,me;
        int i, size,z;

	me = this_object();
	z = get_z(me);
        team2 = ({ });
        size = sizeof(team);
        if( !size ) return team2;
        for( i = 0; i < size; i ++ ) 
                if( team[i] && !team[i]->is_die() && z == get_z(team[i]) )  
                        team2 += ({ team[i] });
        return team2;
}

// �������жϿ���ս��
int can_fight( object who )
{ 
	object me=this_object(),owner;

	owner = who->get_owner();
	if ( !owner ) 
		owner = who;
	if ( me->get("team_id") != owner->get_team_id() )
		return 0;
	return ::can_fight(who);	
}
// ���������Խ���ս��
int can_be_fighted( object who ) 
{ 
	object me=this_object(),owner;

	owner = who->get_owner();
	if ( !owner ) 
		owner = who;
	if ( me->get("team_id") != owner->get_team_id() )
		return 0;
	return ::can_be_fighted(who);	
}

