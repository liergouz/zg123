
#include <npc.h>
#include <skill.h>
#include <effect.h>

inherit CHAR;

inherit "/inh/npc/gift";
inherit "/inh/npc/energy";
inherit "/inh/char/energy2";
inherit "/inh/char/dbase5";
inherit "/inh/char/attack";
inherit "/inh/npc/attack2";
inherit "/inh/char/cmd";
inherit "/inh/char/group";
inherit "/inh/npc/skill";
inherit "/inh/npc/equip";

private string Name;                    // ��������
private int PicId;                      // ��������


private static int Action_Mode = 1;		// ��������  0 �������� 1 ���������� 2 ������
private static int Action = 1;	// ����ģʽ  0 ���� 1 �ж���(���ٻ�����˵���Ǹ���) 2: �����������
private static int NextAction = 1;		// �����ŵľ���ģʽ


private object Owner;                   // ���˶���
private int OwnerNumber;                // ���˶���(Number)

private int Level;                      // �ȼ�

// ������NPC ʶ����
int is_npc() { return 1; }

// -------------------------------------------------------------

// ��������ȡ��������
string get_name() { return Name; }

// ������������������
string set_name( string name ) 
{ 
        if( Name != name ) 
        {
        	Name = name;
        	send_user( get_scene_object_2( this_object(), USER_TYPE ), "%c%c%d%s", 0x3d, 5, getoid( this_object() ), get_short() );
        }
        return Name ; 
}

// ��������ȡ��������
string get_short() 
{ 
        if (this_object()->get_level()) return sprintf("%s(%d��)",get_name(), this_object()->get_level() );
        return get_name(); 
}

// ����������ʶ����
int id( string arg ) 
{ 
        if( !arg || arg == "" ) return 0;
        if( arg[<1] == '#' ) return arg != sprintf( "%x#", getoid( this_object() ) ) ? 0 : 1;
        return arg != get_name() ? 0 : 1;
}

// ��������ȡ��������
int get_char_picid() { return PicId; }

// ������������������
int set_char_picid( int id ) { return PicId = id; }

// ��������ȡ���˶���
object get_owner() { return Owner; }

// �������������˶���
object set_owner( object char ) 
{ 
        if( !objectp(char) ) OwnerNumber = 0;
        else OwnerNumber = char->get_number();
        return Owner = char; 
}

// ��������ȡ���˶���(Number)
int get_owner_number() { return OwnerNumber; }

// �������������˶���(Number)
int set_owner_number( int number ) { return OwnerNumber = number; }

// ��������ȡ�������ȼ�
int get_max_char_level() { return 150; }

// ��������ȡ��߼��ܵȼ�
int get_max_skill_level() { return 150; }

// ��������ȡ�ȼ�����
int get_level() { return Level; }

// ���������õȼ�����
int set_level( int level ) { return Level = range_value( level, 0, get_max_char_level() ); }

// -------------------------------------------------------------

// �������������ú���
void setup()
{
        object me = this_object();

        set_char_type(NPC_TYPE);
        enable_player();

        if( !clonep(me) ) return;

        set_heart_timer( me, set_heart_timer_2(me, getoid(me) % 10) );    // �������
        set_heart_loop(me, 10);    // ѭ��������������
        me->heart_beat();
        set_heart_beat(1);
}

// ������������·
int is_moveable() { return 1; }    // ��ʹ�� go ����

// ��������ȡ����״̬
int get_action() { return Action; }

// �����������ж�״̬
int set_action( int flag ) 
{ 
	object owner;
	object me = this_object();
	int ret, old_flag;
	owner = me->get_owner();	
	old_flag = Action;
	if (owner&&flag<2 && old_flag!=flag)
	{
		if (flag ==0) ret = 3;
		else
		ret = 2;		
		send_user(owner, "%c%c%d%c", 0x2c, 5, getoid(me), ret);
	}	
	return Action = flag; 
}

// ��������ȡ�ж�ģʽ
int get_action_mode() { return Action_Mode; }

// ���������ù���״̬
int set_action_mode( int flag ) 
{ 
	object owner;
	object me = this_object();
	owner = me->get_owner();
	if (owner)
	{
		send_user(owner, "%c%c%d%c", 0x2c, 6, getoid(me), flag);
	}
	return Action_Mode = flag; 
}

// ��������ȡ�ж�ģʽ
int get_next_action() { return NextAction; }

// ���������ù���״̬
int set_next_action( int flag ) 
{
	 return NextAction = flag;
}

// ��������������
void heart_beat() { __FILE__ ->heart_beat_callout( this_object() ); }

// ��������������(���߸���)
void heart_beat_callout( object me )    // ÿ 0.1 �� heart_timer + 1, �� heart_count Ϊ 0 ʱ����
{
        object who;
        string file;
        int heart, count, speed,ret,rate;

        heart = get_heart_timer(me);    // ��ȡ����ʱ��(��)
        count = get_heart_count_2(me);    // ��ȡ�������
        count = set_heart_count_2( me, count - abs( heart - get_heart_timer_2(me) ) );    // ��������֮��

        if( count < 1 )
        {
                switch( get_heart_state(me) )
                {
      case FIGHT_STAT : // ��ͨ����, ���⼼(����)
                        set_heart_state(me, FIGHT_STAT_DONE);
                        set_heart_count_2(me, 2);
                        if( who = me->get_enemy_3() )
                        {
                                if(     stringp( file = me->get_perform_file() ) 
                                &&      load_object(file)
                                &&      file->perform_done_npc(me, who) == 2 )    // �ؼ�����(���)
                                        ;

                                else if( stringp( file = me->get_perform_2_file() ) 
                                &&      load_object(file)
                                &&      file->perform_done_npc(me, who) == 2 )    // �ؼ�����(ѭ��)(���)
                                        ;

                                else
                                {
                                	ret = CHAR_FIGHT_D->attack_done(me, who, HIT_NORMAL);    // ��ͨ����(���)
                        		if( !me ) return;    // �����˳�
					if ( ret && who && !who->is_die() && (rate=me->get("double_attack")) && random(100) < rate )	//2�ι���
						CHAR_FIGHT_D->attack_done(me, who, HIT_NORMAL);

                                	if ( ret && me && !me->is_die() && who && !who->is_die() && me->get("sk74215") && random(100)<20 && !get_effect_3(who, EFFECT_CHAR_DREAM) )
                                	{
				                set_effect_2(who, EFFECT_CHAR_BLOOD, 5, 2);
				                send_user( who, "%c%w%w%c", 0x81, 9022, get_effect_3(who, EFFECT_CHAR_BLOOD), EFFECT_BAD );
				                send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 9022, 1, OVER_BODY, PF_LOOP );
				                send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9022, 1, EFFECT_BAD );        	
				                CHAR_CHAR_D->init_loop_perform(who);
				                who->set_save("char_blood", 20);
                                	}                                		
                                }
                        }
                        if( !me ) return;    // �����˳�
                        me->set_perform_file(0);    // ��Ҫ������Ƿ��ؼ�
                        // ���ú���������ʱ��
                        if(     get_effect(me, EFFECT_CHAR_LAZY)
                        ||      get_effect(me, EFFECT_CHAR_SLOW) )    // ս���ٶȼ���(�����ͷ�)
                                speed = me->get_attack_speed() * 2;
                        else    speed = me->get_attack_speed();     
                        set_heart_count(me, speed - 7 );        
                        set_heart_count_2(me, speed - 7 );           
                        break;

      case MAGIC_STAT : // ���ŷ���(����)
                        set_heart_state(me, WALK_STAT);
                        NPC_HEART_D->heart_beat_cast(me);
                        if( !me ) return;    // �����˳�
                        // ���ú���������ʱ��
                        if(     get_effect(me, EFFECT_CHAR_LAZY)
                        ||      get_effect(me, EFFECT_CHAR_SLOW) )    // ս���ٶȼ���(�����ͷ�)
                                speed = me->get_attack_speed() * 2;
                        else    speed = me->get_attack_speed();     
                        set_heart_count(me, speed - 9 );        
                        set_heart_count_2(me, speed - 9 );                              
                      	break;

              default : if( me->is_caster() )    // Զ�̹����Ĺ�
                        {
                                if(     get_effect(me, EFFECT_CHAR_LAZY)
                                ||      get_effect(me, EFFECT_CHAR_SLOW) )    // ս���ٶȼ���(�����ͷ�)
                                        speed = me->get_attack_speed() * 2;
                                else    speed = me->get_attack_speed();

//                                if( heart % speed == 0 ) 
                                {
                                        me->heart_beat_attack();
                                        if( !me ) return;    // �����˳�
                                }
//                                set_heart_count(me, speed - heart % speed);    // ����������־(��), 0.? ���������(ս��)
                                set_heart_count(me, speed);

                                if( get_heart_count_2(me) < 1 )
                                {
                                        if( get_effect(me, EFFECT_CHAR_LAZY) )
                                                speed = me->get_walk_speed() * 2;
                                        else    speed = me->get_walk_speed();

//                                        if( heart % speed == 0 ) 
                                        {
                                                me->heart_beat_walk();
                                                if( !me ) return;    // �����˳�
                                        }
  //                                      set_heart_count(me, speed - heart % speed);    // ����������־(��), 0.? ���������(��·)
                                        set_heart_count(me, speed);
                                }
                                if( !me ) return;    // �����˳�
                        }
                        else    // �������Ĺ�
                        {
                                if( get_effect(me, EFFECT_CHAR_LAZY) )
                                        speed = me->get_walk_speed() * 2;
                                else    speed = me->get_walk_speed();

//                                if( heart % speed == 0 ) 
                                {
                                        me->heart_beat_walk();
                                        if( !me ) return;    // �����˳�
                                }
//                                set_heart_count(me, speed - heart % speed);    // ����������־(��), 0.? ���������(��·)
                                set_heart_count(me, speed);

                                if( get_heart_count_2(me) < 1 )
                                {
                                        if(     get_effect(me, EFFECT_CHAR_LAZY)
                                        ||      get_effect(me, EFFECT_CHAR_SLOW) )    // ս���ٶȼ���(�����ͷ�)
                                                speed = me->get_attack_speed() * 2;
                                        else    speed = me->get_attack_speed();

//                                        if( heart % speed == 0 ) 
                                        {
                                                me->heart_beat_attack();
                                                if( !me ) return;    // �����˳�
                                        }
//                                        set_heart_count(me, speed - heart % speed);    // ����������־(��), 0.? ���������(ս��)
                                      	set_heart_count(me, speed);
                                }
                                if( !me ) return;    // �����˳�
                        }
                        break;
                }

        }
        else    set_heart_count(me, count);    // ����������־(��), 0.? ���������

        set_heart_timer_2(me, heart);    // ��������ʱ��(��), ��ʾ���Ѵ���
}

private static int HeartSec = 0;        // ������ʱ

// ��������ȡ������ʱ
int get_heart_sec() { return HeartSec; }

// ����������������ʱ
int set_heart_sec( int point ) { return HeartSec = point; }

// ����������������ʱ
int add_heart_sec( int point ) { return set_heart_sec(HeartSec + point); }

// ��������������(ѭ��)
void heart_beat_loop( int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 ) { __FILE__ ->heart_beat_loop_callout( this_object(), effect1, effect2, effect3, effect4, effect5, effect6, effect7, effect8 ); }

// ��������������(ѭ��)(���߸���)
void heart_beat_loop_callout( object me, int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 )    // ÿ���봦��
{
        NPC_EFFECT_D->into_effect(me, effect1, effect2, effect3, effect4, effect5, effect6, effect7, effect8);    // ��״����
        if( !me ) return;    // �����˳�

        NPC_HEART_D->heart_beat_other(me);
        if( !me ) return;    // �����˳�

        if( me->add_heart_sec(1) % 8 == 0 ) NPC_HEART_D->heart_beat_8sec(me);    // ÿ���봦��
}

// �����������������
void init_heart_beat_idle() { set_heart_idle( this_object(), 0 ); }

// ��������·����(����֮�е���)
void heart_beat_walk() { NPC_HEART_D->heart_beat_walk( this_object() ); }

// ��������������(����֮�е���)
void heart_beat_attack() { NPC_HEART_D->heart_beat_attack( this_object() ); }

// �������������(����֮�е���)
void follow_user() { NPC_HEART_D->follow_user( this_object() ); }

// �������жϿ���ս��
int can_fight( object who ) { return NPC_ATTACK_D->can_fight( this_object(), who ); }

// ���������Խ���ս��
int can_be_fighted( object who ) { return NPC_ATTACK_D->can_be_fighted( this_object(), who ); }

// �������Զ�ս��(�����ʱ����)
void auto_fight( object who ) { NPC_ATTACK_D->auto_fight( this_object(), who ); }

// -------------------------------------------------------------

// ������������������
object *correct_bonus_team( object *team ) { return NPC_NPC_D->correct_bonus_team( this_object(), team ); }
// ���������ݾ���������������
object *correct_bonus_team1( object *team,int iDistance ) { return NPC_NPC_D->correct_bonus_team1( this_object(), team,iDistance ); }

// �������������齱��
int correct_exp_bonus( int level, int level2, int exp ) { return NPC_NPC_D->correct_exp_bonus(level, level2, exp); }

// ����������������
int correct_drop_rate( int level ) { return NPC_NPC_D->correct_drop_rate(level); }

// ����������boss������
int correct_drop_rate_2( int level ) { return NPC_NPC_D->correct_drop_rate_2(level); }

// ��������������
void win_bonus( object who ) { NPC_NPC_D->win_bonus( this_object(), who ); }
