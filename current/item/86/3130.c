
// �Զ����ɣ�/make/equip/86z

inherit NECK;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("�޼�����");
        set_picid_1(8613);
        set_picid_2(8613);
        set_unit("��");

        set_level(130);
        set_value(98000);
        set_max_lasting(6399);
        set("cp", 75);
        set("dp", 44);
        set("spec.??%", 15);
        set("spec.X@%", 15);
        set("spec./%", 8);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�޼�����";
}
