
#include <ansi.h>
#include <city.h>

// ���������ɶ�������
void SAVE_BINARY() { }

// ���������ɼ���
void do_skill( object who, object me, string arg )
{
        mapping skls;
        string name1, name2, *name, file;
        int id, skill, i, size;

        id = getoid(me);

        name1 = who->get_org_name();
        name2 = me->get_org_name();

        if( stringp(name1) && stringp(name2) && name1 == name2 )    // �������
        {
                send_user( who, "%c%c%d%c%w%w%s", 0x95, 30, id, who->get_org_position(), 1, 20, me->get_org_name() );

                if( sizeof( skls = me->get_skill_dbase() ) )
                {
                        name = sort_array( keys(skls), 1 );
                        for( i = 0, size = sizeof(name); i < size; i ++ )
                        {
                                skill = to_int( name[i] );
                                file = SKILL->get_skill_file(skill);
                                file = load_object(file) ? file->get_name() : "δ֪����";
                                send_user( who, "%c%c%w%w%d%s", 0x95, 31, skill, me->get_skill(skill), me->get_skill_degree(skill), file );
                        }
                }

                if( skill = me->get_research() )
                {
                        file = SKILL->get_skill_file(skill);
                        file = load_object(file) ? file->get_name() : "δ֪����";
                        send_user( who, "%c%c%w%s", 0x95, 32, skill, file );
                }
        }
}

// �������о�����
void do_research( object who, object me, string arg )
{
        string name1, name2, file, result;
        string cmd1, cmd2, cmd3;
        int id, skill, level, *research, size, i;
        mapping skls;

        id = getoid(me);

        name1 = who->get_org_name();
        name2 = me->get_org_name();
        skls = me->get_researchs();
	research = keys(skls);
	size = sizeof(research);
        if( stringp(name1) && stringp(name2) && name1 == name2 && who->get_org_position() > ORG_PRESBYTER )    // �����Ա
        {
                if( sscanf( arg, "%d.%d", skill, level ) != 2 )
                {
                        if( !( skill = to_int(arg) ) )    // ֹͣ�о�
                        {
                                me->set_research(0);
                                send_user( who, "%c%c", 0x95, 33 );

                                FAMILY_D->org_channel( name2, 0, sprintf( HIR "%s(%d)ֹͣ�о����м��ܣ�", 
                                        who->get_name(), who->get_number() ) );
                        }
                        else if( load_object( file = SKILL->get_skill_file(skill) ) && (file->is_basic_skill()||file->is_vita_skill()) )    // �о�����
                        {
                                cmd1 = sprintf("talk %x# research.%d.1\n", id, skill);
                                cmd2 = sprintf("talk %x# research.%d.2\n", id, skill);
                                cmd3 = sprintf("talk %x# research.%d.3\n", id, skill);
                                send_user( who, "%c%s", ':', me->get_name() + "��\n��ѡ��" + file->get_name() + "�����о��ٶȡ�\n" 
                                        ESC "�����ٶȣ�ÿСʱ  800 �����ȣ�24000 �����Ĵ���1��\n" + cmd1 +
                                        ESC "�ӿ��ٶȣ�ÿСʱ 1200 �����ȣ�48000 �����Ĵ���2��\n" + cmd2 +
                                        ESC "�����ٶȣ�ÿСʱ 1600 �����ȣ�96000 �����Ĵ���3��\n" + cmd3 +
                                        ESC "�������롭��\nCLOSE\n" );
                        }
                        return;
                }
                if (level==0)
                {
                	if (skls[skill]>0)
                	{
                		if( load_object( file = SKILL->get_skill_file(skill) ) )
                		{
	                                me->set_researchs(skill, 0);
	                                send_user( who, "%c%c%w", 0x95, 33, skill );
	
	                                FAMILY_D->org_channel( name2, 0, sprintf( HIR "%s(%d)ֹͣ�о�%s��", 
	                                        who->get_name(), who->get_number(), file->get_name() ) );                			
					return;	                                       
                		}
                	}
                	send_user( who, "%c%s", '!', "����û���о�������ܣ�" );
                	return;
                }
                // ���о����Ŷݼ׺�����
                if (skill==408||skill==409) return;
                // ����о����ܹ�֧�ֵļ�����
                if (skls[skill]==0&&size>=me->get_science()/5+1)
                {
                	send_user( who, "%c%s", '!', "�����о���������ͬʱ������ô�༼�ܡ�" );
                	return;
                }
                if( load_object( file = SKILL->get_skill_file(skill) ) && ( file->is_basic_skill()||file->is_vita_skill() ) )    // �о�����
                {
                	if (level>me->get_grade())
                	{
                		send_user( who, "%c%s", '!', "���ɹ�ģ�����������о��ٶȡ�" );
                		return;
                	}
                        me->set_researchs(skill, level);
                        send_user( who, "%c%c%w%s", 0x95, 32, skill, file->get_name() );

                        switch( level )
                        {
                      default : result = "�����ٶ�";  break;
                       case 2 : result = "�ӿ��ٶ�";  break;
                       case 3 : result = "�����ٶ�";  break;
                        }
			me->save();
                        FAMILY_D->org_channel( name2, 0, sprintf( HIR "%s(%d)��%s��ʼ�о���%s����", 
                                who->get_name(), who->get_number(), result, file->get_name() ) );
                }
        }
}

// ��������������
void do_abandon( object who, object me, string arg )
{
        string name1, name2, file, result;
        string cmd1, cmd2, cmd3;
        int id, skill, level;
        mapping skls;

        id = getoid(me);

        name1 = who->get_org_name();
        name2 = me->get_org_name();

        if( stringp(name1) && stringp(name2) && name1 == name2 && who->get_org_position() > ORG_PRESBYTER )    // �����Ա
        {
                if( sscanf( arg, "%d.%d", skill, level ) != 2 )
                {
                	skill = to_int(arg);
                        if( load_object( file = SKILL->get_skill_file(skill) ) && me->get_skill(skill) && (file->is_basic_skill()||file->is_vita_skill()) )    // �о�����
                        {
                                cmd1 = sprintf("talk %x# abandon.%d.1\n", id, skill);
                                send_user( who, "%c%s", ':', me->get_name() + "��\n    ���Ƿ����ȷ��Ҫ������" + file->get_name() + "�������������������н�Ǯ�Ͷ��޷�������\n" 
                                        ESC "�Ҿ���Ҫ����\n" + cmd1 +
                                        ESC "�������롭��\nCLOSE\n" );
                        }
                        return;
                }

                if( load_object( file = SKILL->get_skill_file(skill) ) && me->get_skill(skill) && ( file->is_basic_skill()||file->is_vita_skill() ) )    // �о�����
                {
                	me->delete_skill(skill);
                	send_user( who, "%c%c%w%w%d%s", 0x95, 31, skill, 0, 0, file->get_name() );
                        FAMILY_D->org_channel( name2, 0, sprintf( HIR "%s(%d)�����˰��ɵġ�%s�����ܣ�", 
                                who->get_name(), who->get_number(), file->get_name() ) );
                }
        }
}
