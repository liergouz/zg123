
// �Զ����ɣ�/make/item/make95

inherit "/inh/item/book3";

// ���������촦��
void create()
{
        set_name("����ǿ��");
        set_picid_1(9808);
        set_picid_2(9808);
        set_unit("��");
        set_value(3000);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��������ɽר�÷�������ǿ�����鼮����ɽʹ�ú��ѧ�ᷨ������ǿ����"; 
}

// ��������ȡ��������
string get_family_name() { return " ��ɽ"; }

// ��������ȡ���ܺ���
int get_skill_id() { return 0329; }

// ��������ȡ����Ҫ��ȼ�
int get_skill_level() { return 19; }

// ��������ȡ�ؼ���־
string get_perform_id() { return "03295"; }

// ��������ȡ��������
string get_skill_name() { return "������ת"; }
