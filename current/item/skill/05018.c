
// �Զ����ɣ�/make/item/make95

inherit "/inh/item/book3";

// ���������촦��
void create()
{
        set_name("ǿ������ɶ�");
        set_picid_1(9808);
        set_picid_2(9808);
        set_unit("��");
        set_value(3000);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "������������ר�÷���ǿ������ɶ���鼮��������ʹ�ú��ѧ�ᷨ��ǿ������ɶ�"; 
}

// ��������ȡ��������
string get_family_name() { return " ������"; }

// ��������ȡ���ܺ���
int get_skill_id() { return 0501; }

// ��������ȡ����Ҫ��ȼ�
int get_skill_level() { return 21; }

// ��������ȡ�ؼ���־
string get_perform_id() { return "05018"; }

// ��������ȡ��������
string get_skill_name() { return "��ҽҩ��"; }
