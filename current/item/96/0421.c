
// �Զ����ɣ�/make/item/make96

inherit "/inh/item/book2";
int get_item_color() { return 2; }
// ���������촦��
void create()
{
        set_name("��˵����ؼ�");
        set_picid_1(9604);
        set_picid_2(9604);
        set_unit("��");
        set_value(50000);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�书�ؼ�������һ������"; 
}

// ��������ȡ��������
string get_family_name() { return " ����ɽ"; }

// ��������ȡ���ܺ���
int get_skill_id() { return 0421; }

// ��������ȡ��������
string get_skill_name() { return "��˵���"; }
