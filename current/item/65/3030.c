
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("��ս��");
        set_picid_1(6574);
        set_picid_2(6574);

        set_level(30);
        set_value(5000);
        set_max_lasting(6699);
        set("dp", 44);
        set("pp", 16);

        setup();

        set_gender(1);
        set_head_code(42);
}

// ��������ȡ����
string get_desc()
{
        return "��ս��";
}
