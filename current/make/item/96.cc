
// �Զ����ɣ�/make/item/make96

inherit "/inh/item/book2";
int get_item_color() { return 2; }
// ���������촦��
void create()
{
        set_name("%s");
        set_picid_1(%d);
        set_picid_2(%d);
        set_unit("%s");
        set_value(%d);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�书�ؼ�������һ������"; 
}

// ��������ȡ��������
string get_family_name() { return "%s"; }

// ��������ȡ���ܺ���
int get_skill_id() { return %04d; }

// ��������ȡ��������
string get_skill_name() { return "%s"; }
