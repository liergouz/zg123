
// �Զ����ɣ�/make/item/make95

inherit "/inh/item/book";
int get_item_color() { return 1; }
// ���������촦��
void create()
{
        set_name("ҩʦ����");
        set_picid_1(9503);
        set_picid_2(9503);
        set_unit("��");
        set_value(10000);
}

// ��������ȡ����
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc() 
{ 
        return "�书�鼮����������������"; 
}

// ��������ȡ��������
string get_family_name() { return " ��"; }

// ��������ȡ���ܺ���
int get_skill_id() { return 0680; }

// ��������ȡ��������
string get_skill_name() { return "ҩʦ"; }
