
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("��ͷ��ñ");
        set_picid_1(6623);
        set_picid_2(6623);

        set_level(45);
        set_value(15300);
        set_max_lasting(6399);
        set("dp", 32);
        set("pp", 53);

        setup();

        set_gender(2);
        set_head_code(53);
}

// ��������ȡ����
string get_desc()
{
        return "��ͷ��ñ";
}
