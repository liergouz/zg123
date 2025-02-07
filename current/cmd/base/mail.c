
#define ADVICE_LOG      "advice.txt"

// �����������
int main( object me, string arg )
{
        object mailbox;
        string who;
        int id;

        if( !arg )
        {
                mailbox = new(MAILBOX);
                mailbox->set_owner( me->get_id() );

                if( mailbox->check_mails() )
                {
                        mailbox->read_mail(me, 1);
                        mailbox->discard_mail(1);
                }

                destruct(mailbox);

                return 1;
        }
        if (time()<me->get_save("nomail"))
        {
        	notify( "�������޷����š�" );
        	return 1;
        }

        if( gone_time( me->get_time("mail") ) < 1 )
        {
                me->set_time( "mail", time() );
                notify( "����Ƶ�������ʼ���" );
                return 1;
        }
        me->set_time( "mail", time() );
        if( sscanf( arg, ">>%s %d %s", who, id, arg ) )    // GM ר��
        {
                if( is_player(me) ) 
                {
                        notify( "��û���㹻��Ȩ�ޡ�" );
        		return 1;
                }

                arg = replace_string(arg, "\\n", "\n" );        
                if( !MAILBOX->sys_mail(who, id, arg) )
                {
                        notify( "�ż�����ʧ�ܣ�" );
        		return 1;
                }
                printf("�ż����ͳɹ���");
                return 1;
        }
        else
        if( sscanf( arg, ">%s %s", who, arg ) )    // GM ר��
        {
                if( is_player(me) ) 
                {
                        notify( "��û���㹻��Ȩ�ޡ�" );
        		return 1;
                }

                arg = replace_string(arg, "\\n", "\n" );
        
                mailbox = new(MAILBOX);
                mailbox->set_owner( me->get_id() );
                if( !mailbox->send_mail_2(me, who, arg) )
                {
                        destruct(mailbox);

                        notify( "�ż�����ʧ�ܣ�" );
        		return 1;
                }
                printf("�ż����ͳɹ���");

                destruct(mailbox);

                return 1;
        }
        else if( sscanf( arg, "%d %s", id, arg ) ) 
        {
                arg = replace_string(arg, "\\n", "\n" );
                if( strlen(arg)>250 ) 
                {
                        notify( "�����ż�̫���ˡ�" );
        		return 1;
                }                
                arg = replace_string(arg, "%", "��" );
                if( id == 0 )    // �� GM �Ὠ��
                {
                        log_file( ADVICE_LOG, sprintf( @LONG
%s(%d)-%s %s
%s

LONG
, me->get_name(), me->get_number(), me->get_id(), short_time(), arg ) );
			notify( "�������������Ѿ��յ�����л���ṩ����Ľ��顣" );
                        return 1;
                }

                mailbox = new(MAILBOX);
                mailbox->set_owner( me->get_id() );
                mailbox->send_mail(me, id, arg);

                destruct(mailbox);

                return 1;
        }

        return 1;
}
