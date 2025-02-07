#include <time.h>
#include <npc.h>
#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <task.h>

private int Reincarnation;              // ת������

private int UpgradeExp;                 // ��������
private int BillionExp;                 // �ܾ���(ʮ�ڱ�־)
private int Experience;                 // �ܾ���
private int Potential;                  // Ǳ��
private int Total_bonus;		//�ܹ��µ�
private int Bonus;                      // ���� 10����1��
private int GiftPoint;                  // ���Ե�
private int MaxLevel;                   // ��ߵȼ�(�������Ե�)
private int Level;                      // �ȼ�

private int Cash;                       // �ֽ�
private int Savings;                    // ���
private string Marry;                   // ��ż
private int Divorced;                   // ������
private int PK;                         // PK ��־
private int clean_pk_time;		//���PK��־ʱ���
private int max_pawn;                   // �������

private static int TaskXY;              // ��������
private static mapping mpTaskXY ;       // �ۺ���������

int get_login_flag();

int set_level( int level ) ;

// -------------------------------------------------------------
//��ȡ���PK��־ʱ��
int get_clean_pk_time() { return clean_pk_time; }
//�������PK��־ʱ��
int set_clean_pk_time(int time) { return clean_pk_time=time; }
//�������PK��־ʱ��
int add_clean_pk_time(int time) { return set_clean_pk_time(clean_pk_time+time); }
// ��������ȡת������
int get_reincarnation() { return Reincarnation; }

// ����������ת������
int set_reincarnation( int life ) { return Reincarnation = range_value(life, 0, 2); }

// ��������ȡ�������ȼ�
int get_max_char_level()
{
//	if ( MAIN_D->get_host_type() == 4 || MAIN_D->get_host_type() == 6012 )
//		return 120;
        return 150;
}

// ��������ȡ�������ȼ�
int get_max_char_level_2()
{
//	if ( MAIN_D->get_host_type() == 4 || MAIN_D->get_host_type() == 6012 )
//		return 120;
        return 150;
}
// ��������ȡ��߼��ܵȼ�
int get_max_skill_level()
{
//	if ( MAIN_D->get_host_type() == 4 || MAIN_D->get_host_type() == 6012 )
//		return 120;
        return 150;
}

// ��������ȡ��߼��ܵȼ�
int get_max_skill_level_2() { return 150; }

// ��������ȡ��߼��ܵȼ�
int get_max_skill_level_3()
{
        return 150;
}

// ��������ȡ��߼��ܵȼ�(����)
int get_max_basic_skill_level_2() { return 350; }

// ��������ȡ��߼��ܵȼ�(����)
int get_max_basic_skill_level_3()
{
        return 150;
}

/* // ��������ȡ���мӳ���
int get_pf_rate()
{
        switch( Reincarnation )
        {
      default : return 0;
       case 1 : return 20;
       case 2 : return 40;
        }
}       */

int get_skill( int skill );
int get_skill_1( int skill );
int get_skill_1_2( int skill );

// ��������ȡ���й�ʽֵ(���� /skill)
int get_pf_value( int skill, int square, int a, int b )
{
        int level = get_skill(skill);
        int square2 = level * (level + 1);
        return a + (square2 - square) / b;
}

// ��������ȡ���й�ʽֵ(���� /skill)
int get_pf_value_2( int skill, int square, int a, int b )    // ͬת�����
{
        int level = get_skill(skill);
        int square2 = level * (level + 1);

        switch( Reincarnation )
        {
      default : return a + (square2 - square) / b;
       case 1 : return a * (120 + get_skill_1(skill) ) / 100 + (square2 - square) / b * 100 / 80;
       case 2 : return a * (140 + get_skill_1_2(skill) ) / 100 + (square2 - square) / b * 100 / 60;
        }
}

// ��������ȡ���Ե㱶��
int get_gift_point_times()
{
        switch( Reincarnation )
        {
      default : return 4;
       case 1 : return 6;
       case 2 : return 8;
        }
}

// ��������ȡ��߹��µ���
int get_max_bonus()
{
        switch( Reincarnation )
        {
      default : return 20000;
       case 1 : return 40000;
       case 2 : return 80000;
        }
}

// ��������ȡ������������
int get_max_pawn_size()
{
	if ( !max_pawn )
	{
	        switch( Reincarnation )
	        {
	      default : return max_pawn=Level / 10 + 1;
	       case 1 : return max_pawn=Level / 10 + 14;    // +13
	       case 2 : return max_pawn=Level / 10 + 28;    // +13 +14
	        }
	}

	return max_pawn;
}

// ���������õ�����������
int set_max_pawn_size(int i)
{
	return max_pawn=range_value(i,1,100);
}

// ��������ȡ����װ���ȼ�
int get_equip_less_level()
{
        switch( Reincarnation )
        {
      default : return 0;
       case 1 : return 10;
       case 2 : return 20;
        }
}

// -------------------------------------------------------------

// ��������ȡ��������
int get_upgrade_exp() { return UpgradeExp; }

// ������������������
int set_upgrade_exp( int exp )
{
	int max;
	object me = this_object();
	max = USER_EXP_D->get_upgrade_exp_limit(me);	//��ȡ��������
	if (exp> max)
	{
		send_user(me, "%c%s", '!', "�����Ѵ�����" );
		exp = max;
	}
	return UpgradeExp = range_value(exp, -MAX_NUMBER, MAX_NUMBER);
}

// ������������������
int add_upgrade_exp( int exp ) { return set_upgrade_exp( UpgradeExp + exp ); }

// ��������ȡ�����־(ʮ��)
int get_billion_exp() { return BillionExp; }

// ���������þ����־(ʮ��)
int set_billion_exp( int exp ) { return BillionExp = range_value(exp, 0, 1000); }    // ���ޣ�����

// �������������־(ʮ��)
int add_billion_exp( int exp ) { set_billion_exp( BillionExp + exp ); }

// ��������ȡ��������
int get_exp() { return Experience; }

// ���������þ�������
varargs int set_exp( int exp, int bil_exp )
{
        object me;
        string result;
        int status;

        if( bil_exp != 0 )    // exp, bil_exp ����ͬ��
        {
                if( bil_exp > 0 && exp < 0 ) bil_exp = 0;
                if( bil_exp < 0 && exp > 0 ) bil_exp = 0;
        }

        BillionExp = bil_exp + exp / BILLION_NUMBER;
        Experience = exp % BILLION_NUMBER;

        if( Level < 10 && UpgradeExp >= USER_EXP_D->get_level_exp(Reincarnation, Level) )
        {
                me = this_object();

                USER_EXP_D->recount_user_level(me);
	        USER_ENERGY_D->count_all_prop(me);

                me->set_hp( me->get_max_hp() );    // ����������Ѫ
                me->set_mp( me->get_max_mp() );

                send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(me),
                        9043, 1, OVER_BODY, 9044, 1, OVER_BODY, PF_ONCE );

                result = sprintf( HIC "������ %d ����", Level );
                send_user( me, "%c%s", '!', result );
                write_user(me, result);
		TEACHER_D->add_shifu_exp(me,1);	//����ʦ������
		if (me->get_org_name()!="") "/sys/sys/manager"->upgrade(me);		
		"/quest/zg_dict"->player_can_be_gala(me,1);	//	�������ս�������Լ�ҡ������
        }
        else
        if( Level < 11 && UpgradeExp >= USER_EXP_D->get_level_exp(Reincarnation, Level) )
        {
        	me = this_object();
        	status = me->get_save("tips_status");
		if ((status & 32)==0)    // ��һ������
		{
			notify( "��ͨ��������Խ����е�������ť������" );
			status |= 32;
			me->set_save("tips_status", status);
		}
		"/quest/help"->send_help_tips(me, 19);
        }
        if( get_login_flag() >= 3 )
                send_user( this_object(), "%c%c%w%d%d", 0x3d, 40, BillionExp, Experience, UpgradeExp );

        return Experience;
}


// �������ֶ�����
int Upgrade()
{
        object me;
        string result;
        mixed *mxTime;
        int status;
        int sub_exp;
	sub_exp = USER_EXP_D->get_level_exp(Reincarnation, Level);
        if( Level < get_max_char_level() && UpgradeExp >= sub_exp  )
        {
                me = this_object();
		me->set_upgrade_exp(UpgradeExp - sub_exp);
                set_level(Level+1);
                me->count_gift();
	        USER_ENERGY_D->count_all_prop(me);

                me->set_hp( me->get_max_hp() );    // ����������Ѫ
                me->set_mp( me->get_max_mp() );

                send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(me),
                        9043, 1, OVER_BODY, 9044, 1, OVER_BODY, PF_ONCE );

                result = sprintf( HIC "������ %d ����", Level );
                send_user( me, "%c%s", '!', result );
                write_user(me, result);
                mxTime = localtime(time());
		log_file(sprintf("levelup_%d%02d%02d.txt", mxTime[TIME_YEAR], mxTime[TIME_MON]+1, mxTime[TIME_MDAY]),sprintf("%s %s %d %s %d %s\n",short_time(),me->get_id(),me->get_number(),me->get_name(),Level,me->get_fam_name()));
		TEACHER_D->add_shifu_exp(me,sub_exp);	//����ʦ������
		if (me->get_org_name()!="") "/sys/sys/manager"->upgrade(me);
		"/quest/zg_dict"->player_can_be_gala(me,1);	//	�������ս�������Լ�ҡ������
        }

        if( get_login_flag() >= 3 )
                send_user( this_object(), "%c%c%w%d%d", 0x3d, 40, BillionExp, Experience, UpgradeExp );

        return Experience;
}

// ����������������
int add_exp( int exp )
{
        set_upgrade_exp( UpgradeExp + exp );    // ͬ��Ӱ�� upgrade_exp���� set_exp ǰ
	TASK_MASTER_D->check_quest(this_object(), exp, 2);
        if( BillionExp == 0 )
        {
                set_exp( Experience + exp );
        }
        else if( BillionExp > 0 )
        {
                if( exp > 0 )
                {
                        Experience += exp % BILLION_NUMBER;
                        BillionExp += Experience / BILLION_NUMBER;
                        set_exp(Experience, BillionExp);
                }
                else if( exp < 0 )
                {
                        Experience += exp % BILLION_NUMBER + BILLION_NUMBER;
                        BillionExp --;
                        set_exp(Experience, BillionExp);
                }
        }
        else
        {
                if( exp < 0 )
                {
                        Experience += exp % BILLION_NUMBER;
                        BillionExp += Experience / BILLION_NUMBER;
                        set_exp(Experience, BillionExp);
                }
                else if( exp > 0 )
                {
                        Experience += exp % BILLION_NUMBER - BILLION_NUMBER;
                        BillionExp ++;
                        set_exp(Experience, BillionExp);
                }
        }

        return Experience;
}

// ��������ȡ���Ǳ��
int get_max_potential() { return range_value(Level, 1, MAX_NUMBER) * 1000; }    // ע���µ�¼���

// ��������ȡǱ������
int get_potential() { return Potential; }

// ����������Ǳ������
int set_potential( int point )
{
        if( point > get_max_potential() ) send_user( this_object(), "%c%s", '!', "����Ǳ�������������������ˡ�" );
        point = range_value( point, 0, get_max_potential() );
        if( Potential != point && get_login_flag() > 1 ) send_user( this_object(), "%c%c%d", 0x3d, 41, point );
        return Potential = point;
}

// ����������Ǳ������
int add_potential( int point )
{
	TASK_MASTER_D->check_quest(this_object(), point, 3);
	return set_potential( Potential + point );

}

// ��������ȡ���µ�
int get_bonus() { return Bonus; }
//��������ȡ�ܹ��µ�
int get_total_bonus() {return Total_bonus;}
// ���������ù��µ�
int set_bonus( int point )
{
        point = range_value( point, 0, get_max_bonus() );
        if( Bonus != point && get_login_flag() > 1 ) send_user( this_object(), "%c%c%d", 0x3d, 42, point / 10 );
        if(point>0) Total_bonus=point;
        return Bonus = point;
}

// ���������ӹ��µ�
int add_bonus( int point ) { return set_bonus( Bonus + point ); }

// ��������ȡ���Ե�
int get_gift_point() { return GiftPoint; }

// �������������Ե�
int set_gift_point( int point )
{
        if( GiftPoint != point && get_login_flag() > 1 ) send_user( this_object(), "%c%c%w", 0x3d, 43, point );
        return GiftPoint = point;
}

// �������������Ե�
int add_gift_point( int point ) { return set_gift_point( GiftPoint + point ); }

// ��������ȡ��ߵȼ�
int get_max_level() { return MaxLevel; }

// ������������ߵȼ�
int set_max_level( int point ) { return MaxLevel = point; }

// ������������ߵȼ�
int add_max_level( int point ) { return set_max_level( MaxLevel + point ); }

// ��������ȡ�ȼ�����
int get_level() { return Level; }

// ���������õȼ�����
int set_level( int level )
{
        object leader, me, *inv;
        int point, i, size, number;

        me = this_object();

        if( is_player(me) )
                level = range_value( level, 0, get_max_char_level() );
        else    level = range_value( level, 0, get_max_char_level_2() );

        if( Level != level && get_login_flag() > 1 )
        {
                send_user( me, "%c%c%w%d", 0x3d, 44, level, USER_EXP_D->get_level_exp(Reincarnation, level) );

                //��ʱ��Ϊ�ͻ��˲������������飬���Լ������
	        send_user( me, "%c%c%w%d%d%d%w%w%d%d%d%d", 0x3d, 164,
        	        me->get_billion_exp(), me->get_exp(), me->get_potential(), me->get_bonus() / 10, me->get_gift_point(),
                	level, me->get_upgrade_exp(), USER_EXP_D->get_level_exp( me->get_reincarnation(), level ), me->get_cash(), me->get_savings() );
                if (get_login_flag()>=3)
                {
			switch(level)
			{
			case 1:
				QUEST_TIPS->send_tips(me, "3");
				break;
			case 2:
				QUEST_TIPS->send_tips(me, "5");
				break;
			case 3:
				QUEST_TIPS->send_tips(me, "6");
				break;
			case 4:
				QUEST_TIPS->send_tips(me, "7");
				break;
			case 5:
				QUEST_TIPS->send_tips(me, "8");
				break;
			case 6:
				QUEST_TIPS->send_tips(me, "9");
				break;
			case 8:
				QUEST_TIPS->send_tips(me, "11");
				break;
			case 10:
//				QUEST_TIPS->send_tips(me, "2");
//				"/inh/user/mail"->sys_mail2(me->get_id(), me->get_number(), "�ٺ�����", "��ϲ��˳��������ʮ������˵�������������ִ壨192��149������һ����������Ļ����һ��������㲻�ٰ����ġ�\n");
				break;
			case 11:
				QUEST_TIPS->send_tips(me, "10");
				break;
			case 30:
				QUEST_TIPS->send_tips(me, "12");
				break;
			case 60:
				QUEST_TIPS->send_tips(me, "13");
				break;
			}
			"/quest/help"->send_level_tips(me, level);
		}
                if( level > MaxLevel )
                {
                        add_gift_point( (level - MaxLevel) * get_gift_point_times() );
                        "/quest/help"->send_help_tips(me, 20);
                        "/quest/help"->send_help_tips(me, 36);
//			if (me->get_save("testbonus")) add_gift_point( (level - MaxLevel) * 2 );
                        if( MaxLevel < 30 )    // ����������
                        {
                                if( leader = me->get_bonus_leader() )
                                {
                                        switch( MaxLevel )
                                        {
                                    case 0..9 : point = (level - MaxLevel) * 5;  break;
                                  case 10..19 : point = (level - MaxLevel) * 20;  break;
                                  case 20..29 : point = (level - MaxLevel) * 40;  break;
                                      default : point = 0;  break;
                                        }

                                        leader->add_bonus(point);
                                        write_user(leader, ECHO "������" HIY "%s" ECHO "���� %d ��(%+d)�������� " HIY "%+d.%d" ECHO "��",
                                                me->get_name(), level, level - MaxLevel, point / 10, point % 10 );

                                        if( level >= 30 ) TEAM_D->check_bonus_task( me->get_leader() );    // ���Ҫ������
                                }
                        }

                        MaxLevel = level;
                }
                inv = me->get_team();
                number = me->get_number();
		for( i = 0, size = sizeof(inv); i < size; i ++ ) if( inv[i] )
		{
		        if (me->get_number()!=inv[i]->get_number()) send_user( inv[i], "%c%c%d%c", 0x54, 5, number, level );
		}
                if( !MAP_D->is_inside_battle( get_z(me) ) ) switch( Level )    // �����������
                {
            case 0..9 : switch( level )
                        {
                    case 0..9 : break;
                  case 10..29 : USER_D->sub_level_a_user(me);  USER_D->add_level_b_user(me);  break;
                      default : USER_D->sub_level_a_user(me);  USER_D->add_level_c_user(me);  break;
                        }
                        break;

          case 10..29 : switch( level )
                        {
                    case 0..9 : USER_D->sub_level_b_user(me);  USER_D->add_level_a_user(me);  break;
                  case 10..29 : break;
                      default : USER_D->sub_level_b_user(me);  USER_D->add_level_c_user(me);  break;
                        }
                        break;

              default : switch( level )
                        {
                    case 0..9 : USER_D->sub_level_c_user(me);  USER_D->add_level_a_user(me);  break;
                  case 10..29 : USER_D->sub_level_c_user(me);  USER_D->add_level_b_user(me);  break;
                      default : break;
                        }
                        break;
                }
        }

        return Level = level;
}

// -------------------------------------------------------------

// ��������ȡ����ֽ�
int get_max_cash() { return MAX_NUMBER; }    // ע���µ�¼���

// ��������ȡ�����ֽ�
int get_cash() { return Cash; }

// ���������������ֽ�
int set_cash( int gold )
{
        if( gold > get_max_cash() ) send_user( this_object(), "%c%s", '!', "�����ֽ��Ѵ����ޣ������������ˡ�" );
        gold = range_value( gold, 0, get_max_cash() );    // - MAX_NUMBER
        if( Cash != gold && get_login_flag() > 1 ) send_user( this_object(), "%c%c%d", 0x3d, 70, gold );
        return Cash = gold;
}

// ���������������ֽ�
int add_cash( int gold )
{
	object who = this_object();
	object obj, *all;
	string result;
	int i, size;
	all = previous_object(-1);
	obj = previous_object();
	all -= ({ who, 0 });
	size = sizeof(all);
        for (i=size-1;i>=0;i--)
        {
		if (all[i]->is_npc())
		{
			obj = all[i];
			break;
		}
        }
        if (obj && obj->is_npc())
        {
        	if (gold>0)
        		result = sprintf("��� @%s %s,%d,%s,%s �� 0 %d 0 %d_%d_%d", obj->get_name(), who->get_name(), who->get_number(), get_ip_name(who), who->get_id(),  gold, get_z(who), get_x(who), get_y(who) );
        	else
        		result = sprintf("�ۼ� @%s %s,%d,%s,%s �� 0 %d 0 %d_%d_%d", obj->get_name(), who->get_name(), who->get_number(), get_ip_name(who), who->get_id(),  gold, get_z(who), get_x(who), get_y(who) );
        	"/sys/user/cmd"->log_item(result);
        }
        else
        if (obj)
        {
	        if (gold>0)
	        	result = sprintf("��� @%s %s,%d,%s,%s �� 0 %d 0 %d_%d_%d", get_file_name(obj), who->get_name(), who->get_number(), get_ip_name(who), who->get_id(),  gold, get_z(who), get_x(who), get_y(who) );
	        else
	        	result = sprintf("�ۼ� @%s %s,%d,%s,%s �� 0 %d 0 %d_%d_%d", get_file_name(obj), who->get_name(), who->get_number(), get_ip_name(who), who->get_id(),  gold, get_z(who), get_x(who), get_y(who) );
	        "/sys/user/cmd"->log_item(result);

        }
	return set_cash(Cash + gold);
}

// �������м�¼��add_cash
int add_cash2( int gold ) { return set_cash(Cash + gold); }

// ��������ߴ����
int get_max_savings()
{
        switch( Reincarnation )
        {
      default : return range_value(Level, 1, MAX_NUMBER) * 1000000;    // ע���µ�¼���
       case 1 : return range_value(Level, 1, MAX_NUMBER) * 2000000;
       case 2 : return range_value(Level, 1, MAX_NUMBER) * 4000000;
        }
}

// ��������ȡ�洢���
int get_savings() { return Savings; }

// ���������ô洢���
int set_savings( int gold )
{
        if( gold > get_max_savings() ) send_user( this_object(), "%c%s", '!', "���Ĵ���Ѵ����ޣ������������ˡ�" );
        gold = range_value( gold, - MAX_NUMBER, get_max_savings() );
        if( Savings != gold && get_login_flag() > 1 ) send_user( this_object(), "%c%c%d", 0x3d, 71, gold );
        return Savings = gold;
}

// ���������Ӵ洢���
int add_savings( int gold ) { return set_savings(Savings + gold); }

// ��������ȡ���±�ʶ
string get_marry() { return Marry; }

// ���������ð��±�ʶ
string set_marry( string id ) { return Marry = id; }

// ��������ȡ������
int get_divorced() { return Divorced; }

// ����������������
int set_divorced( int num ) { return Divorced = num; }

// ����������������
int add_divorced( int num ) { return Divorced += num; }

// ��������ȡ�У˱�־
int get_pk() { return range_value(PK, 0, 65535); }    // ���棺��ֹ������

// ���������ãУ˱�־
int set_pk( int flag )
{
        object me = this_object();
        int old_pk = PK;

        PK = range_value(flag, 0, MAX_NUMBER);

        if (old_pk<5 && PK>=5)
        {
                send_user( me, "%c%c%w%s", ':', 3, 0, "��Ϊ���������أ�����������ʱ�����ȥ�����ǻ��ڵ�����Ե������ս���ϴ��ɡ�\n"
                        ESC "ȷ��\nCLOSE\n" );
        }
        else
        if (old_pk>0 && PK==0)
        {
                send_user( me, "%c%c%w%s", ':', 3, 0, "��Ϊ�������ڣ����Ѿ��������������Ѿ������ƽ�ľ��硣\n"
                        ESC "ȷ��\nCLOSE\n" );
        }
        else
        if (PK>old_pk)
        {
        	set_effect(me, EFFECT_USER_PK, 600);
        	me->set_attack_mode(0);
        }
        if (PK>=5) me->set_attack_mode(0);
        if( PK<5 && me->get_attack_mode()==0 )
        {
                me->set_char_type(PK_TYPE);    // �����У�״̬
        }
        else switch( PK )
        {
       case 0 : me->set_char_type(PLAYER_TYPE_2);  break;
    case 1..2 : me->set_char_type(PK_TYPE_1);  break;
    case 3..4 : me->set_char_type(PK_TYPE_3);  break;
      default : me->set_char_type(PK_TYPE_5);  break;
        }

        return range_value(PK, 0, 65535);    // ���棺��ֹ������
}

// ���������ӣУ˱�־
int add_pk( int flag ) { return set_pk( PK + flag ); }

// �������Ƿ�У���
int is_pker()
{
        switch( PK )
        {
    case 0..2 : return 0;
    case 3..5 : return 1;
      default : return 2;
        }
}

// ��������ȡ��������
int get_task_xy() { return TaskXY; }

// ������������������
varargs int set_task_xy( int p, int x, int y )    // ֧�����ַ�ʽ
{
        if( !x && !y ) return TaskXY = p;

        return TaskXY = p * 1000000 + x * 1000 + y;
}

// ��������ȡ�ۺ���������
mapping get_mtask_xy()
{
	if ( !mapp(mpTaskXY) )
		return ([]);
	return copy(mpTaskXY);
}

// �����������ۺ���������
int set_mtask_xy( int z, int x, int y, string id,string intro )    // id:�ο�send_mtask_xy
{
	if ( !id ) return 0;
	if ( x<=0 && y<=0 && mapp(mpTaskXY) && mapp(mpTaskXY[z])  )
		map_delete(mpTaskXY[z],id);
	if ( !mapp(mpTaskXY) )
		mpTaskXY = ([]);
	if ( !mapp(mpTaskXY[z]) )
		mpTaskXY[z] = ([]);
	if ( !stringp(intro) ) intro = "";
	mpTaskXY[z][id] = (["xy":x * 1000 + y,"intro":intro,]);
        return 1;
}

void send_mtask_xy(int z)
{
	int i,size,x0,y0;
	string *nId,id;
	object me=this_object();
	if ( !mapp(mpTaskXY) || !mapp(mpTaskXY[z]) )
		return ;
	nId = keys(mpTaskXY[z]);
	for(i=0,size=sizeof(nId);i<size;i++)
	{
		id = nId[i];
		if ( !find_any_char(sprintf("%x#",id))  ) continue;
                x0 = ( mpTaskXY[z][id]["xy"])/ 1000;
                y0 = ( mpTaskXY[z][id]["xy"]) % 1000;
                send_user( me, "%c%c%d%w%w%s", 0x54, 12, id, x0, y0,mpTaskXY[z][id]["intro"] );
	}

}