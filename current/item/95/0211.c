
// �Զ����ɣ�/make/item/make95

inherit "/inh/item/book";
int get_item_color() { return 1; }
// ���������촦��
void create()
{
        set_name("̫����ȭ����");
        set_picid_1(9504);
        set_picid_2(9504);
        set_unit("��");
        set_value(10000);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�书�鼮����������������"; 
}

// ��������ȡ��������
string get_family_name() { return " �һ�Դ"; }

// ��������ȡ���ܺ���
int get_skill_id() { return 0211; }

// ��������ȡ��������
string get_skill_name() { return "̫����ȭ"; }
