
// �Զ����ɣ�/make/equip/88z

inherit BOOTS;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("׷����");
        set_picid_1(8813);
        set_picid_2(8813);
        set_unit("˫");

        set_level(130);
        set_value(39000);
        set_max_lasting(9699);
        set("dp", 24);
        set("pp", 35);
        set("spec.??%", 15);
        set("spec.?%", 15);
        set("spec.c?%", 8);
        set("spec.X@%", 8);
        set("spec./%", 8);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "׷����";
}
